#include<bits/stdc++.h>
using namespace std;
#define N 200020
const int mod=998244353;
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
int T,n;
ll a[N],s1[N],s2[N],s0[N];
int calc(ll t,int z0,int z1){
	int tot=0;
	if(!(z0&&!z1)&&t+s0[n]>0)++tot;
	for(int i=1;i<=n-(!z1);++i){
		int l=1,r=i+2,now=0;
		while(l<r){
			int mid=(l+r)>>1;
			if(t+s0[n]-s0[i]-s0[i]+2*(i&1?s2[i]-s2[mid-1]:s1[i]-s1[mid-1])>0){
				now=mid,l=mid+1;	
			}
			else{
				r=mid;
			}
		}
		tot=(tot+(now+1)/2)%mod;
		if(now>=1&&z0&&!(i&1))tot=(tot+mod-1)%mod;
	}
	return tot;
}
int Solve(){
	n=read();
	ll x=read();
	if(n==1)return 1;
	n-=2;
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	ll y=read();
	for(int i=1;i<=n;++i){
		s0[i]=s0[i-1]+a[i];
		s1[i]=s1[i-1]+(i&1?a[i]:0);
		s2[i]=s2[i-1]+(i&1?0:a[i]);
	}
	int ans=(((calc(x-y,1,0)+calc(x+y,1,1))%mod+calc(-x+y,0,1))%mod+calc(-x-y,0,0))%mod;
	for(int i=0;i<=n;++i){
		if(s0[i]+x>s0[n]-s0[i]+y)ans=(ans+1)%mod;
	}
	return ans;
}
int main(){
	T=read();
	while(T--){
		printf("%d\n",Solve());
	}
	return 0;
}