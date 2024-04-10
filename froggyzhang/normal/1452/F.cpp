#include<bits/stdc++.h>
using namespace std;
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
int n,Q;
ll all,cnt[31];
ll Query(int d,ll k){
	static ll a[31];
	memcpy(a,cnt,sizeof(cnt));
	if(k>all)return -1;
	ll ans=0;
	for(int i=0;i<=d;++i)k-=a[i];
	if(k<=0)return 0;
	for(int i=d+1;i<n;++i){
		ll p=min(k/(1LL<<i-d),a[i]);
		k-=(1LL<<i-d)*p;
		a[i]-=p;
		a[d]+=(1LL<<i-d)*p;
		ans+=((1LL<<i-d)-1)*p;
	}
	
	ll res=0;
	for(int i=0;i<=d;++i){
		res+=((1LL<<i)-1)*a[i];
	}
	if(res>=k)return ans+k;
	for(int i=d+1;i<n;++i){
		if(a[i]){
			for(int j=i;j>=d+1;--j){
				int tmp=0;
				while(k>=(1LL<<j-d)&&a[j])k-=1LL<<(j-d),ans+=(1LL<<j-d)-1,--a[j],++tmp;
				res+=(1LL<<j-d)*tmp*((1<<d)-1);
				if(res>=k)return k+ans;
				if(a[j]){
					a[j-1]+=2,++ans;
					if(j==d+1)k=max(0LL,k-2);
				} 
			}
			return ans+k;
		}	
	}
	return 233;
}
int main(){
	n=read(),Q=read();
	for(int i=0;i<n;++i){
		cnt[i]=read();
		all+=cnt[i]*(1LL<<i);
	}
	while(Q--){
		int opt=read();
		if(opt==1){
			int x=read();
			all-=cnt[x]*(1LL<<x);
			cnt[x]=read();
			all+=cnt[x]*(1LL<<x);
		}
		else{
			int x=read();ll k=read();
			printf("%lld\n",Query(x,k));		
		}
	}
	return 0;
}