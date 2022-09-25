#include<bits/stdc++.h>
using namespace std;
#define N 400040
typedef long long ll;
const int mod=998244353;
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
int b[N],n,ans,s[N];
struct Seg{
	int l,r,o;
}a[N];
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i].r=read(),a[i].l=read();
		a[i].o=read();
		b[i]=a[i].r,b[i+n]=a[i].l;
	}
	sort(b+1,b+2*n+1);
	ans=(b[n<<1]+1)%mod;
	for(int i=1;i<=n;++i){
		a[i].l=lower_bound(b+1,b+2*n+1,a[i].l)-b;
		a[i].r=lower_bound(b+1,b+2*n+1,a[i].r)-b;	
	}
	for(int i=1,j=1;i<=(n<<1);++i){
		s[i]=s[i-1];
		if(a[j].r==i){
			int tmp=(b[a[j].r]-b[a[j].l]+s[a[j].r]-s[a[j].l])%mod;
			tmp=(tmp+mod)%mod;
			s[i]=(s[i]+tmp)%mod;
			if(a[j].o)ans=(ans+tmp)%mod;
			++j;	
		}
	}
	printf("%d\n",ans);
	return 0;
}