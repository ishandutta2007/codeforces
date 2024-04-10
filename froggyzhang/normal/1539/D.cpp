#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n;
pair<ll,ll> a[N];
ll sum;
bool check(ll x){
	ll now=sum-x;
	for(int i=1;i<=n&&x;++i){
		ll res=min(a[i].second,x);
		if(a[i].first>now)return false;
		now+=res;
		x-=res;
	}
	return true;
}
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i].second=read(),a[i].first=read();
		sum+=a[i].second;
	}
	sort(a+1,a+n+1);
	ll l=0,r=sum+1,ans=0;
	while(l<r){
		ll mid=(l+r)>>1;
		if(check(mid)){
			l=mid+1,ans=mid;
		}
		else{
			r=mid;
		}
	}
	printf("%lld\n",2*sum-ans);
	return 0;
}