/*
AuThOr GaRyMr
*/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define LL long long
#define IT iterator
#define PB push_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
const int MAGIC=2000;
int block(int x){
	return x/MAGIC+bool(x%MAGIC);
}
int n,m,q; 	
char maze[100000+10][11],v[100000+10][11];mp res[100000+10][11];
mp dfs(int x,int y){
	if(x==0||y==0||y==m+1){
		return  II(x,y);
	}
	if(v[x][y] ) return res[x][y];
	v[x][y]=1;
	if(maze[x][y]=='>'){
		if(y+1!=m+1&&maze[x][y+1]=='<'){
			return  res[x][y]=II(x,y);
		}
		return res[x][y]=dfs(x,y+1);
	}
	if(maze[x][y]=='<'){
		if(y-1!=0&&maze[x][y-1]=='>'){
			return res[x][y]=II(x,y);
		}
		return res[x][y]=dfs(x,y-1);
	}
	if(maze[x][y]=='^'){
		if(x-1!=0)
		if(block(x)!=block(x-1)){
			return res[x][y]=II(x-1,y);
		}
		return res[x][y]=dfs(x-1,y);
	}
	return II(1,1);
}
int main(){
	fastio;
	cin>>n>>m>>q;
	rb(i,1,n)	
		rb(j,1,m)
			cin>>maze[i][j];
	rb(i,1,n)
		rb(j,1,m)
			dfs(i,j);
	rb(Q,1,q){
		char cp;
		cin>>cp;
		if(cp=='C'){
			int x,y;
			char c;
			cin>>x>>y>>c;
			int BLOCK=block(x);
			maze[x][y]=c;
			int S,T;
			S=(BLOCK-1)*MAGIC+1;
			T=BLOCK*MAGIC;
			T=min(T,n);
			rb(i,S,T)
				rb(j,1,m)
					v[i][j]=0;
			rb(i,S,T)
				rb(j,1,m)
					dfs(i,j);
			
		}
		else{
			int x,y;
			cin>>x>>y;
			mp now=res[x][y];
			int las=block(now.FIR)+1;
			while(block(now.FIR)==las-1&&now.FIR&&now.SEC&&now.SEC!=m+1){
				las=block(now.FIR);
				now=res[now.FIR][now.SEC];
			}
			if(!now.FIR||!now.SEC||now.SEC==m+1){
				cout<<now.FIR<<" "<<now.SEC<<endl;
			}
			else{
				cout<<-1<<" "<<-1<<endl; 
			}
		}
	}
	return 0;
}