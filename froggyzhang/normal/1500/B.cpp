#include<bits/stdc++.h>
using namespace std;
#define N 1000010
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
int n,m,a[N],b[N],g,pos[N],cnt[N];
ll K,Lcm;
inline ll check(ll t){
	ll ans=0,tp=t/Lcm;
	int p=0;
//	cerr<<" jk!  "<<t<<" "<<(t/Lcm)*m<<" "<<n<<" "<<m<<" "<<Lcm<<endl;
	do{
		ans+=1LL*tp*cnt[p];
		p=(p+m)%n;
		t-=tp*m;
	}while(p);
	for(;;){
		if(t<m){
			int c=0;
			for(int j=p;t;j=(j+1)%n,++c){
				--t;
				ans+=b[c]==a[j];
			}
			return ans;
		}
		ans+=cnt[p];
		p=(p+m)%n;
		t-=m;
	}
}
int main(){
	n=read(),m=read(),K=read();
	for(int i=0;i<n;++i)a[i]=read();
	for(int i=0;i<m;++i)b[i]=read();
	g=__gcd(n,m);
	if(n<m){
		swap(n,m);
		swap(a,b);
	}
	memset(pos,-1,sizeof(pos));
	for(int i=0;i<m;++i)pos[b[i]]=i;
	Lcm=1LL*n*m/g;
	for(int i=0;i<n;++i){
		if(~pos[a[i]]){
			++cnt[i-pos[a[i]]<0?i-pos[a[i]]+n:i-pos[a[i]]];
		}
	}
	ll l=K,r=2e18,ans=0;
	while(l<r){
		ll mid=(l+r)>>1;
		if(mid-check(mid)>=K){
			ans=r=mid;
		}
		else{
			l=mid+1;
		}
	}
	printf("%lld\n",ans);
	return 0;
}