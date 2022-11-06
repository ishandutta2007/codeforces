#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=5e5+10;
const int mo=1e9+7;
const int inf=1e9;
int a[N],h[N],s[N];ll l[N],r[N];
int main(){int n;
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]);
	int tot=0;ll nw=0;
	rep(i,1,n){int sum=0;
		while(tot&&h[tot]>=a[i]){
			nw-=1ll*(h[tot]-a[i])*s[tot];
			sum+=s[tot--];
		}
		l[i]=nw;++sum;nw+=a[i];
		h[++tot]=a[i];s[tot]=sum;
	}nw=tot=0;
	dep(i,n,1){int sum=0;
		while(tot&&h[tot]>=a[i]){
			nw-=1ll*(h[tot]-a[i])*s[tot];
			sum+=s[tot--];
		}
		r[i]=nw;++sum;nw+=a[i];
		h[++tot]=a[i];s[tot]=sum;
	}
	ll ans=0;int ps=1;
	rep(i,1,n)if(a[i]+l[i]+r[i]>ans){
		ans=a[i]+l[i]+r[i];ps=i;
	}
	dep(i,ps-1,1)a[i]=min(a[i],a[i+1]);
	rep(i,ps+1,n)a[i]=min(a[i],a[i-1]);
	rep(i,1,n)printf("%d%c",a[i],i==n?'\n':' ');
}