#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int N=1e6+10;
const int mo=998244353;
const ll inf=1e18;
ll a[N],b[N];int p[22],tot;
int main(){int k;
	scanf("%d",&k);int K=min(999999,(k-1)*3);
	rep(i,0,20){
		if(K<=(1<<i)){
			p[++tot]=K;break;
		}else p[++tot]=1<<i,K-=1<<i;
	}
	sort(p+1,p+tot+1);
	int nw=1;
	rep(i,1,999999)a[i]=-inf;
	rep(o,0,5){ll w;
		scanf("%lld",&w);
		rep(i,1,tot){
			if(3ll*p[i]*nw>999999)break;
			int x=3*p[i]*nw;
			dep(j,999999,x)a[j]=max(a[j],a[j-x]+p[i]*w);
		}
		rep(i,0,999999)b[i]=a[i];
		rep(i,1,9){
			if(i*nw>999999)break;
			int x=i*nw;ll W=0;
			if(!(i%3))W=i/3*w;
			dep(j,999999,x)a[j]=max(a[j],b[j-x]+W);
		}
		nw*=10;
	}
	int q;scanf("%d",&q);
	rep(i,1,q){int x;
		scanf("%d",&x);
		printf("%lld\n",a[x]);
	}
}