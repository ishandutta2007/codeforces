/*
	Name: I will do my best in the next round #564 & #566
	Copyright: 
	Author: 
	Date: 04/06/19 21:02
	Description: 
*/

/*######################################################################
	
	!
	
	dfs or bfs
	
	c[i]
	
	long long
	
	dp
	
	:AABAB
	 >=0
	
	double> printf("%lf")6%.16lf
	
	dpg
	n8
	
	find if(l>=b||r<=a) return 0x3f3f3f3f; if(r<=b&&l>=a) return tree[k];
	 
	 
	
	priority_queue<> q;   
	priority_queue<,vector<>, less<> > pq1;  // 	
	priority_queue<vector<>, greater<> > pq2; // 
	
	1<<int(ceil(log2(double(n))))
	or
	
	
	make_pair 
	
	: dp[i]=dp[i-1]*2-dp[last[i]-1]
*/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;a++)
#define rl(a,b,c) for(int a=b;a>=c;a--)
#define niv vector<int>
#define LL long long
#define IT iterator
#define PB(a) push_back(a)
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
using namespace std;
const int INF=0x3f3f3f3f;
const int MAXN=3e5+10; 
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
struct node{
	vector<int> son_set;
	int have=0;
}each_node[MAXN];
int  n;//n<=3e5
int type[MAXN];
int leaves_number=0;
int _tmp=0;
int my_map[MAXN][2];
inline void dfs(int now,int con){
//	cout<<now<<" "<<con<<endl;
	if(my_map[now][con]){
		_tmp+=my_map[now][con];
		return ;
	}
	if(each_node[now].son_set.size()==0){
		if(con) _tmp++;
		return ;
	}//cout<<now<<endl;
	int save_data=_tmp;
	if(con==0){
		return ;
	}
	if(type[now]){//get maximum
		int id,best_minus=INF;
		int sz=each_node[now].son_set.size();
		rb(i,0,sz-1){
			dfs(each_node[now].son_set[i],1);
			int one=_tmp-save_data;
			my_map[each_node[now].son_set[i]][1]=one;
			_tmp=save_data;
			dfs(each_node[now].son_set[i],0);
			int two=_tmp-save_data;
			_tmp=save_data;
			if(one-two<best_minus){
				best_minus=one-two;
				id=i;
			}
		}
		_tmp=save_data;
//		cout<<"start"<<endl;
		dfs(each_node[now].son_set[id],1);
		rb(i,0,sz-1){
			if(i==id) continue;
			dfs(each_node[now].son_set[i],0);
		}
	}
	else{
		int sz=each_node[now].son_set.size();
		rb(i,0,sz-1){
			dfs(each_node[now].son_set[i],1);
		}
	}
}
inline bool check(int x){
	memset(my_map,0,sizeof(my_map));
	_tmp=0;
	dfs(1,1);
	if(_tmp<=leaves_number-x+1){
		return true;
	}
	else return false;
}
inline void before_hand(int now){
	if(each_node[now].son_set.size()==0) return ;
	int sz=each_node[now].son_set.size();
	rb(i,0,sz-1){
		before_hand(each_node[now].son_set[i]);
		each_node[now].have+=each_node[each_node[now].son_set[i]].have;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	rb(i,1,n){
		cin>>type[i];
	}
	rb(i,2,n){
		int tmp_parent;
		cin>>tmp_parent;
		each_node[tmp_parent].son_set.PB(i);
	}
	rb(i,1,n){
		if(!each_node[i].son_set.size()){
			leaves_number++;
			each_node[i].have++;
		}
	}
	before_hand(1);
//	rb(i,1,n) cout<<each_node[i].have<<" ";cout<<endl;//OKOKOKOK
	int l=1,r=leaves_number+1;
	while(l<r-1){
//		cout<<l<<" "<<r<<endl;
		int mid=(l+r)>>1;
		if(check(mid)) l=mid;
		else r=mid;
//		cout<<endl;
	}
//	cout<<check(4);
	cout<<l;
	return 0;
}