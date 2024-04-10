//* AuThOr GaRyMr *//
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define niv vector<int>
#define LL long long
#define IT iterator
#define PB(a) push_back(a)
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
map<int,int> represent;
char museum[1000+10][1000+10];
int v[1000+10][1000+10];
int direx[4]={0,0,1,-1},direy[4]={1,-1,0,0};
int tot=0;
inline void dfs(int x,int y){
	if(v[x][y]) return;
	v[x][y]=tot;
	rb(i,0,3){
		int nextx=x+direx[i],nexty=y+direy[i];
		if(museum[nextx][nexty]=='*') represent[tot]++;
		else if(!v[nextx][nexty]){
			dfs(nextx,nexty);
		}
	}
	
}
int main(){
	int n,m,k;
	cin>>n>>m>>k;
	rb(i,1,n){
		rb(j,1,m){
			cin>>museum[i][j];
		}
	}
	rb(i,1,n){
		rb(j,1,m){
			if(!v[i][j]&&museum[i][j]=='.'){
				tot++;
				dfs(i,j);
			}
		}
	}
	while(k--){
		int qx,qy;
		cin>>qx>>qy;
		cout<<represent[v[qx][qy]]<<endl;
	}
	return 0;
}