#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,l,r,k,len,ans;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>l>>r>>k;
	len=l<=r?r-l+1:r+(n-l+1);
	ans=-1;
	if(n<=1e6){
		for(ll i=0;i<=n;++i){
			ll s=k%(n+i);
			if(!s)s=n+i;
			s-=len;
			if(s>=max(0LL,i-n+len-1)&&s<=min(len,i)){
				ans=max(ans,i);
			}
		}
	}
	else{
		if(k>=len&&k<=2*len)ans=max(ans,min(n,n-len+k-len+1));
		for(ll i=1;i<=k/n;++i){
			ll L=max((k-2*len+i-1)/i,(k-len+n+i)/(i+1));
			ll R=min((k-2*len+2*n+1)/(i+1),(k-len)/i);
			if(L<=R){
				ans=max(ans,R-n);
			}
		}
	}
	cout<<ans<<'\n';
	return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,l,r,k,l1,l2,i,b,a,ans;
inline void work(int v){
	ll k=::k-v;
	if(n<k/n){
		for(b=n;b>=0;--b){
			ll z=l2+b,y=k-l1;if(y<0)continue;
			i=max((y-min(b,l1-1)+z-1)/z,0ll);
			a=y-i*z;
			if(v<=b && 0<=a && a<=b && a<=l1-1 && b<=l2-l1+1+a)ans=max(ans,b);
		}
	}
	else{
		for(i=0;i*l2<=k;++i){
			ll y=k-i*l2-l1;if(y<0)continue;
			if(i==0 && y>l1-1)continue;
			b=min(l2,min((y+l2-l1+1)/(i+1),i?y/i:1ll<<60));
			a=y-b*i;
			if(v<=b && 0<=a && a<=b && a<=l1-1 && b<=l2-l1+1+a)ans=max(ans,b);
		}
	}
}
int main(){
	scanf("%lld%lld%lld%lld",&n,&l,&r,&k);
	l2=n;l1=l<=r?r-l+1:r+n-l+1;
	ans=-1;
	work(0);work(1);
	printf("%lld\n",ans);
	return 0;
}
*/