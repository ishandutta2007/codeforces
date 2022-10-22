/*
	*#*#*#* Author GaryMr *#*#*#*
########################################################################
	
	
	c[i]
	
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
#define IT iterator
#define FIR first
#define SEC second
using namespace std;
const int MAX=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
map<mp,int> m;
int n,ansflag=0;
void dfs(int x,int y,vector<int> last,vector<int> now,vector<int> next){
	
	if(ansflag) return;
	if(y>n){
		rb(i,1,n){
			if(last[i]==0&&m[make_pair(x-1,i)]==0){
				return;
			}
		}
		vector<int> v(55,0);
		dfs(x+1,1,now,next,v);
		return;
	}
//	cout<<x<<" "<<y<<endl; 
//	cout<<x<<" "<<y<<endl;
	if(x==n){
		rb(i,1,n){
			if(now[i]==0&&m[make_pair(x,i)]==0){
				return;
			}
			if(last[i]==0&&m[make_pair(x-1,i)]==0){
				return;
			}
		}
		ansflag=1;
		return;
	}
	if(y==n||y==1){
		dfs(x,y+1,last,now,next);
		return ;
	}
	if(m[make_pair(x,y)]||now[y]==1){
		dfs(x,y+1,last,now,next);
		return ;
	}
	dfs(x,y+1,last,now,next);
	if((last[y]==0&&m[make_pair(x-1,y)]==0)&&(now[y-1]==0&&m[make_pair(x,y-1)]==0)&&(now[y]==0&&m[make_pair(x,y)]==0)&&(now[y+1]==0&&m[make_pair(x,y+1)]==0)&&(next[y]==0&&m[make_pair(x+1,y)]==0)){
//		cout<<x<<" "<<y<<endl;
		if(last[y-1]==0&&m[make_pair(x-1,y-1)]==0) return;
		last[y]=1;
		now[y-1]=1;
		now[y]=1;
		now[y+1]=1;
		next[y]=1;
		dfs(x,y+1,last,now,next);
		return;
	}
}
int main(){
	cin>>n;
	int tot=0;
	rb(i,1,n){
		rb(j,1,n){
			char c;
			cin>>c;
			if(c=='#'){
				m[make_pair(i,j)]=1;
			}
			else{
				tot++;
			}
		}
	}
//	if(tot%5){
//		cout<<"NO";
//		return 0;
//	}
	vector<int> v1(55,0);
	vector<int> v2(55,0);
	vector<int> v3(55,0);
	dfs(2,1,v1,v2,v3);
	if(ansflag==1){
		cout<<"YES";
	}
	else{
		cout<<"NO";
	}
	return 0;
}