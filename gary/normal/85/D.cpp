/*
	*#*#*#* Author GaryMr *#*#*#*
########################################################################
	
	dfs or bfs
	c[i]	
	
	SET:
	MULTISET: 
	
	
	long long
	
	dp
	
	 >=0
	
	dpg
	n8
	
	find if(l>=b||r<=a) return 0x3f3f3f3f; if(r<=b&&l>=a) return tree[k];
	 
	 
	
	priority_queue<> q;   
	priority_queue<,vector<>, less<> > pq1;  // 	
	priority_queue<vector<>, greater<> > pq2; // 
	
	1<<ceil(log2(double(n)))
*/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;a++)
#define rl(a,b,c) for(int a=b;a>=c;a--)
#define niv vector<int>
#define LL long long
#define IT iterator
#define FIR first
#define SEC second
#define MK(a,b) make_pair(a,b)
using namespace std;
const int MAX=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
queue<pair<char,int> > query;
const int T=1<<17;
LL tree[5][8*T];
int cnt[8*T];
set<int> addnum_set;
map<int,int> li;
void update(int NODE){
	if(!NODE) return ;
	int l=NODE*2,r=NODE*2+1;
	cnt[NODE]=cnt[l]+cnt[r] ;//cout<<cnt[NODE]<<" "<<NODE<<endl;
	rb(i,0,4) tree[i][NODE]=tree[i][l]+tree[(i-cnt[l]%5+5)%5][r];
	update(NODE/2) ;
} 
int main(){//cout<<T<<endl;
	memset(tree,0,sizeof(tree));
	memset(cnt,0,sizeof(cnt));
	int Q;
	scanf("%d",&Q);
	rb(i,1,Q){
		string TYPE;
		int num=0;
		cin>>TYPE;
		if(TYPE[0]=='a'){
			scanf("%d",&num);
			addnum_set.insert(num);
			query.push(MK('a',num));
//			cout<<i<<endl;
		}
		if(TYPE[0]=='s'){			
			query.push(MK('s',num));
//			cout<<i<<endl;
		}
		if(TYPE[0]=='d'){
			scanf("%d",&num);
			query.push(MK('d',num));
//			cout<<i<<endl;
		}
	}
	int now=0;
	set<int> :: IT ite=addnum_set.begin();
	for(ite;ite!=addnum_set.end();ite++){
		li[*ite]=++now;
//		cout<<*ite<<"->" <<now<<endl;
	}
	rb(i,1,Q){
		char TYPE=query.front().FIR;
		int process_num=query.front().SEC;
		query.pop();
		if(TYPE=='s'){
			printf("%I64d\n",tree[3][1]);
		}
		else if(TYPE=='a'){
			int node=li[process_num]+T-1;
			cnt[node]=1;
			tree[1][node]=process_num;
			update(node/2);
		}
		else{//delete
			int node=li[process_num]+T-1;
			cnt[node]=0;
			tree[1][node]=0;
			update(node/2);
		}
	}
	return 0;
}