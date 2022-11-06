#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int N=1010;
const int inf=1e9;
const int mo=1e9+7;
const int u1[]={0,1,0,-1};
const int u2[]={-1,0,1,0};
int t[N][N];char s[N][N];
int main(){int n,m,q;
	scanf("%d%d%d",&n,&m,&q);
	rep(i,1,n)scanf("%s",s[i]+1);
	rep(i,1,n)rep(j,1,m)t[i][j]=inf;
	rep(i,1,n)rep(j,1,m){
		if(i<n&&s[i][j]==s[i+1][j]){
			t[i][j]=t[i+1][j]=0;
		}
		if(j<m&&s[i][j]==s[i][j+1]){
			t[i][j]=t[i][j+1]=0;
		}
	}
	queue<pii>qu;
	rep(i,1,n)rep(j,1,m)if(!t[i][j])qu.push({i,j});
	while(!qu.empty()){
		int x=qu.front().fr,y=qu.front().sc;
		qu.pop();int tt=t[x][y]+1;
		rep(i,0,3){
			int X=x+u1[i],Y=y+u2[i];
			if(X>=1&&X<=n&&Y>=1&&Y<=m&&t[X][Y]==inf){
				t[X][Y]=tt;qu.push({X,Y});
			}
		}
	}
	rep(i,1,q){int x,y;ll z;
		scanf("%d%d%lld",&x,&y,&z);
		int ans=s[x][y]-'0';
		if(t[x][y]<inf&&z>t[x][y])ans^=(z-t[x][y])&1;
		printf("%d\n",ans);
	}
}