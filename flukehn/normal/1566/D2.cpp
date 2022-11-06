#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=311*311;
int a[N],b[N];
int vis[311][311], tot[311];
int main(){
#ifdef flukehn
	freopen("d.in","r",stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;cin>>T;
	while(cin>>n>>m){
		for(int i=0;i<n*m;++i)cin>>a[i];
		for(int i=0;i<n*m;++i)b[i]=a[i];
		sort(b,b+n*m);
		for(int i=0;i<=n;++i)for(int j=0;j<=m;++j)vis[i][j]=0;
		for(int i=0;i<n;++i)tot[i]=0;
		int ans=0;
		for(int o=0;o<n*m;++o){
			int l=lower_bound(b,b+n*m,a[o])-b;
			int r=upper_bound(b,b+n*m,a[o])-b-1;
			if(l/m==r/m){
				int x=l/m;
				int y=r%m;
				while(vis[x][y])--y;
				for(int i=0;i<y;++i)ans+=vis[x][i];
				vis[x][y]=1;
				++tot[x];
			}else{
				int x=l/m,y=m-1;
				while(y>=0&&vis[x][y])--y;
				if(x*m+y>=l){
					vis[x][y]=1;
					++tot[x];
					for(int i=0;i<y;++i)ans+=vis[x][i];
				}else{
					do ++x;while(tot[x]==m);
					if(x==r/m) y=r%m;
					else y=m-1;
					while(vis[x][y])--y;
					vis[x][y]=1;
					++tot[x];
					for(int i=0;i<y;++i)ans+=vis[x][i];
				}
			}
		}
		cout<<ans<<"\n";
	}
}