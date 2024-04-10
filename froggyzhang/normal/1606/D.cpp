#include<bits/stdc++.h>
using namespace std;
#define N 500050
typedef long long ll;
int n,m;
vector<int> a[N],premn[N],sufmn[N],premx[N],sufmx[N];
vector<bool> ok1[N],ok2[N];
void Solve(){
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		a[i].clear();
		a[i].resize(m+1);
		ok1[i].clear();
		ok1[i].resize(m+1);
		ok2[i].clear();
		ok2[i].resize(m+1);
		premn[i].resize(m+2);
		sufmn[i].resize(m+2);
		premx[i].resize(m+2);
		sufmx[i].resize(m+2);
	}	
	for(int i=1;i<=n;++i){
		premn[i][0]=1e6+1;
		premx[i][0]=0;
		for(int j=1;j<=m;++j){
			cin>>a[i][j];
			premn[i][j]=min(premn[i][j-1],a[i][j]);
			premx[i][j]=max(premx[i][j-1],a[i][j]);
		}
		sufmn[i][m+1]=1e6+1;
		sufmx[i][m+1]=0;
		for(int j=m;j>=1;--j){
			sufmn[i][j]=min(sufmn[i][j+1],a[i][j]);
			sufmx[i][j]=max(sufmx[i][j+1],a[i][j]);
		}
	}
	static int p[N],rk[N];
	for(int i=1;i<=n;++i)p[i]=i;
	sort(p+1,p+n+1,[&](int i,int j){return a[i][1]<a[j][1];});
	for(int i=1;i<=n;++i){
		rk[p[i]]=i;	
	}
	for(int i=1;i<n;++i){
		if(a[p[i]][1]<a[p[i+1]][1]){
			ok1[i][1]=1;
		}
	}
	for(int j=2;j<=m;++j){
		static int jbmn[N],jbmx[N];
		sort(p+1,p+n+1,[&](int x,int y){return a[x][j]<a[y][j];});
		int mx=0;
		jbmn[n+1]=1e6+1;
		for(int i=n;i>=1;--i){
			jbmn[i]=min(jbmn[i+1],premn[p[i]][j]);
		}
		jbmx[0]=0;
		for(int i=1;i<=n;++i){
			jbmx[i]=max(jbmx[i-1],premx[p[i]][j]);
		}
		for(int i=1;i<n;++i){
			mx=max(mx,rk[p[i]]);
			if(jbmx[i]<jbmn[i+1]&&mx==i&&ok1[i][j-1]){
				ok1[i][j]=1;
				
			}
		}
	}
	for(int j=m;j>=1;--j){
		static int jbmn[N],jbmx[N];
		sort(p+1,p+n+1,[&](int x,int y){return a[x][j]>a[y][j];});
		int mn=n+1;
		jbmn[0]=1e6+1;
		for(int i=1;i<=n;++i){
			jbmn[i]=min(jbmn[i-1],sufmn[p[i]][j]);
		}
		jbmx[n+1]=0;
		for(int i=n;i>=1;--i){
			jbmx[i]=max(jbmx[i+1],sufmx[p[i]][j]);
		}
		for(int i=n;i>1;--i){
			mn=min(mn,rk[p[i]]);
			if(jbmn[i-1]>jbmx[i]&&mn==i&&(j==m||ok2[i][j+1])){
				ok2[i][j]=1;
			}
		}
	}
	sort(p+1,p+n+1,[&](int i,int j){return a[i][1]<a[j][1];});
	for(int j=1;j<m;++j){
		for(int i=1;i<n;++i){
			if(ok1[i][j]&&ok2[i+1][j+1]){
				cout<<"YES\n";
				static int ans[N];
				for(int k=1;k<=n;++k)ans[k]=0;
				for(int k=1;k<=i;++k){
					ans[p[k]]=1;
				}
				for(int k=1;k<=n;++k){
					cout<<(ans[k]?'B':'R');
				}
				cout<<' '<<j<<'\n';
				return;	
			}	
		}
	}
	cout<<"NO\n";
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		Solve();
	}
	return 0;
}