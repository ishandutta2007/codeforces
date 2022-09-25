#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
vector<int> G[N],H[N];
int d[N],n,m,cntA[N],cntB[N],cntC[N];
ull ans,A,B,C;
vector<pii> E;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	cin>>A>>B>>C;
	for(int i=0;i<n;++i){
		ans+=i*((ull)i*(i-1)/2*C+(ull)i*(n-i-1)*B+(ull)(n-i-1)*(n-i-2)/2*A);
	}
	for(int i=1;i<=m;++i){
		int u,v;
		cin>>u>>v;
		if(u>v)swap(u,v);
		E.emplace_back(u,v);
		++d[u],++d[v];
		++cntA[0],--cntA[u];
		++cntB[u+1],--cntB[v];
		++cntC[v+1];
		ans-=(B*u+C*v)*u+(A*u+C*v)*(v-u-1)+(A*u+B*v)*(n-1-v);
	}
	for(int i=1;i<n;++i){
		cntA[i]+=cntA[i-1];
		cntB[i]+=cntB[i-1];
		cntC[i]+=cntC[i-1];
	}
	for(int i=0;i<n;++i){
		ans-=(cntA[i]*A+cntB[i]*B+cntC[i]*C)*i;	
	}
	for(auto [u,v]:E){
		H[u].push_back(v);
		H[v].push_back(u);
		if(d[u]<=d[v]){
			G[u].push_back(v);
		}
		else{
			G[v].push_back(u);
		}
	}
	for(int i=0;i<n;++i){
		int L=0,R=0;
		for(auto x:H[i]){
			if(x<i)++L;
			else ++R;
		}
		ans+=i*((ull)L*(L-1)/2*C+(ull)L*R*B+(ull)R*(R-1)/2*A);
		sort(H[i].begin(),H[i].end());
		for(int j=0;j<(int)H[i].size();++j){
			int x=H[i][j];
			if(x<i){
				ans+=(B*j+A*((int)H[i].size()-j-1))*x;
			}
			else{
				ans+=(B*((int)H[i].size()-j-1)+C*j)*x;	
			}
		}
	}
	for(int u=1;u<=n;++u){
		static bool vis[N];
		for(auto v:G[u]){
			vis[v]=1;
		}
		for(auto v1:G[u]){
			for(auto v2:G[v1]){
				if(vis[v2]){
					int p0=u,p1=v1,p2=v2;
					if(p0>p1)swap(p0,p1);
					if(p1>p2)swap(p1,p2);
					if(p0>p1)swap(p0,p1);
					ans-=A*p0+B*p1+C*p2;	
				}
			}
		}
		for(auto v:G[u]){
			vis[v]=0;
		}
	}
	cout<<ans<<'\n';
	return 0;
}