#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int N=5e5+10;
const int mo=1e9+7;
const ll inf=1e9;
int a[N],f[N];
int gf(int x){return x==f[x]?x:f[x]=gf(f[x]);}
void sol(){int n;ll ans=0;
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]);
	rep(i,1,n+1)f[i]=i;
	rep(i,1,n)if(a[i]==1)f[i]=i+1;
	while(gf(1)!=n+1){
		int x=gf(1);
		if(x+a[x]>n+1){
			ans+=a[x]-(n-x+1);a[x]=n-x+1;
			if(a[x]==1)f[x]=x+1;
		}
		while(a[x]>1){
			++ans;int i=x;
			while(i<=n){
				if(--a[i]==1)f[i]=i+1;
				i+=a[i]+1;
				if(i<=n&&a[i]==1)i=gf(i);
			}
		}
	}
	printf("%lld\n",ans);
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}