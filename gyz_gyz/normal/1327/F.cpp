#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=5e5+10;
const int inf=1e9;
const int mo=998244353;
int L[N],R[N],X[N],l[N],v[N];ll f[N];
int main(){int n,m,k;
	scanf("%d%d%d",&n,&k,&m);ll ans=1;
	rep(i,1,m)scanf("%d%d%d",&L[i],&R[i],&X[i]);
	rep(i,0,k-1){f[0]=1;
		rep(j,1,n+1)l[j]=v[j]=0;
		rep(j,1,m)if((X[j]>>i)&1){
			++v[L[j]];--v[R[j]+1];
		}else l[R[j]+1]=max(l[R[j]+1],L[j]);
		rep(j,1,n+1){
			v[j]+=v[j-1];l[j]=max(l[j],l[j-1]);
		}
		rep(j,1,n+1){ll res;
			if(!v[j]){
				res=f[j-1];
				if(l[j])res=(res+mo-f[l[j]-1])%mo;
			}else res=0;
			f[j]=(f[j-1]+res)%mo;
			if(j==n+1)ans=ans*res%mo;
		}
	}
	printf("%lld\n",ans);
}