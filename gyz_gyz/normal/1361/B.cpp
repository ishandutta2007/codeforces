#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>pii;
const int N=1e6+10;
const int inf=1e9;
const int mo=1e9+7;
int a[N];
ll qk(ll x,int y){ll r=1;
	for(;y;y>>=1){
		if(y&1)r=r*x%mo;x=x*x%mo;
	}return r;
}
void sol(){int n;ll p;
	scanf("%d%lld",&n,&p);
	rep(i,1,n)scanf("%d",&a[i]);
	if(p==1){
		printf("%d\n",n&1);return;
	}
	sort(a+1,a+n+1);
	ll nw=0,w;bool fl=0;
	dep(i,n,1){
		if(!fl&&!nw){
			++nw;w=a[i];
		}else{
			while(w>a[i]){
				--w;nw*=p;
				if(fl||nw>=mo){
					fl=1;nw=nw%mo*qk(p,w-a[i])%mo;w=a[i];
				}
			}
			nw=(nw+mo-1)%mo;
		}
	}
	nw=nw*qk(p,w)%mo;
	printf("%lld\n",nw);
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}