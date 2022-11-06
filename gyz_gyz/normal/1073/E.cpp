#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) x=(x+(y))%mo
#define pb push_back
#define ll long long
#define N 2000000
#define mo 998244353
#define inf 1000000000
#define Inf 5000000000000000000ll
using namespace std;
ll l,r,a[1024],t[10],w[10];int k;bool v[10];
ll cal(ll x){ll ans=0;
	rep(i,2,1023){ll al=0,tot=0;
		rep(j,0,9){
			v[j]=(i>>j)&1;
			if(v[j])al++;
		}
		ll d=1;a[i]=0;w[0]=v[0];
		rep(j,1,9){
			w[j]=w[j-1]+v[j];
			t[j]=t[j-1]+v[j]*j;
		}
		if(al>k)continue;
		while(x/d>=10)d*=10;bool fl=0;ll nw=0;
		while(d){
			ll s=x/d%10;d/=10;
			if(fl)a[i]=(a[i]*al*10+(tot+!v[0])*t[9])%mo;
			tot=(tot+(!v[0]&&fl))*al%mo;fl=1;
			if(s){
				a[i]=(a[i]+t[s-1]+nw*w[s-1])%mo;
				tot=(tot+w[s-1])%mo;
			}
			if(!v[s]){
				for(;d;d/=10){
					a[i]=(a[i]*al*10+(tot+!v[0])*t[9])%mo;
					tot=((tot+!v[0])*al)%mo;
				}
			}
			nw=(nw+s)*10%mo;
		}
		rep(j,2,i-1)if((i&j)==j)a[i]=(a[i]+mo-a[j])%mo;
		ans=(ans+a[i])%mo;
	}
	return ans;
}
int main(){
	scanf("%lld%lld%d",&l,&r,&k);
	printf("%lld\n",(cal(r+1)+mo-cal(l))%mo);
}