#include<bits/stdc++.h>
using namespace std;
#define N 1020
typedef long long ll;
int n,m,K,p[N],col[N],x[N],y[N];
mt19937 rnd(time(0));
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>K;
	for(int i=1,x;i<=n;++i)cin>>x;
	for(int i=1;i<=m;++i){
		cin>>x[i]>>y[i];
		p[i]=i;
	}
	while(true){
		static int cnt[105][N];
		memset(cnt,0,sizeof(cnt));
		shuffle(p+1,p+m+1,rnd);
		for(int i=1;i<=m;++i){
			int u=x[p[i]],v=y[p[i]];
			int mn=1e9,z=0;
			for(int j=1;j<=K;++j){
				int w=cnt[u][j]+cnt[v][j];
				if(w<mn){
					mn=w,z=j;
				}	
			}
			col[p[i]]=z;
			++cnt[u][z],++cnt[v][z];
		}
		bool ok=true;
		for(int i=1;i<=n;++i){
			if((*max_element(cnt[i]+1,cnt[i]+K+1))-(*min_element(cnt[i]+1,cnt[i]+K+1))>2){ok=false;break;}	
		}
		if(ok)break;
	}
	for(int i=1;i<=m;++i){
		cout<<col[i]<<'\n';
	}
	return 0;
}