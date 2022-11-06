#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=3e5+10;
const int inf=1e9;
const int mo=998244353;
vector<int>r;
int p[N],c[N];bool v[N];
void dfs(int x){
	if(v[x])return;v[x]=1;
	r.push_back(c[x]);dfs(p[x]);
}
void sol(){int n;
	scanf("%d",&n);int ans=n;
	rep(i,1,n)v[i]=0;
	rep(i,1,n)scanf("%d",&p[i]);
	rep(i,1,n)scanf("%d",&c[i]);
	rep(i,1,n)if(!v[i]){
		r.clear();dfs(i);
		int m=r.size();
		rep(j,1,m)if(!(m%j)){bool ok=0;
			rep(k,0,j-1){bool fl=1;
				rep(l,1,m/j-1)if(r[(l-1)*j+k]!=r[l*j+k]){
					fl=0;break;
				}
				if(fl){
					ans=min(ans,j);ok=1;break;
				}
			}
			if(ok)break;
		}
	}
	printf("%d\n",ans);
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}