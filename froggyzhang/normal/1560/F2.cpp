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
int T,n,a[20],m,k,cnt[1<<10];;
void Solve(){
	n=read(),k=read();
	int _n=n;
	m=0;
	while(n)a[++m]=n%10,n/=10;
	int o=0;
	for(int i=1;i<=m;++i){
		o|=1<<a[i];
	}
	if(cnt[o]<=k){
		printf("%d\n",_n);return;
	}
	for(int i=1;i<=m;++i){
		for(int p=a[i]+1;p<=9;++p){
			int x=1<<p;
			for(int j=i+1;j<=m;++j){
				x|=1<<a[j];	
			}
			if(cnt[x]>k)continue;
			int ans=0,z=__builtin_ctz(x);
			for(int j=m;j>=1;--j){
				ans=ans*10+(j>i?a[j]:(j==i?p:(cnt[x]==k?z:0)));	
			}
			printf("%d\n",ans);
			return;
		}
	}
	assert(false);
}
int main(){
	for(int i=1;i<(1<<10);++i){
		cnt[i]=cnt[i>>1]+(i&1);	
	}
	T=read();
	while(T--){
		Solve();
	}
	return 0;
}