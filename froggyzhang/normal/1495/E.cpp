#include<bits/stdc++.h>
using namespace std;
#define N 5000050
#define M 200020
const int mod=1e9+7;
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
int n,a[N],ans[N],m;
bool t[N];
int p[M],k[M],b[M],w[M];
int seed,base;
inline int rnd(){
	int tmp=seed;
	seed=(1LL*seed*base+233)%mod;
	return tmp;
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=m;++i){
		p[i]=read(),k[i]=read(),b[i]=read(),w[i]=read();
	}
	for(int i=1;i<=m;++i){
		seed=b[i],base=w[i];
		for(int j=p[i-1]+1;j<=p[i];++j){
			t[j]=(rnd()&1);
			a[j]=(rnd()%k[i])+1;
		}
	}
	if(t[1]){
		for(int i=1;i<=n;++i)t[i]^=1;
	}
	ll s0=0,s1=0;
	for(int i=1;i<=n;++i){
		if(t[i])s1+=a[i];
		else s0+=a[i];
	}
	//cerr<<" ?? "<<s0<<" "<<s1<<endl;
	if(s0<=s1){
		for(int i=1,j=1;i<=n;++i){
			if(!t[i]){
				ans[i]=a[i];
				if(j<i)j=i;
				int res=a[i];
				while(res){
					if(!t[(j-1)%n+1]){
						++j;
						continue;
					}
					int u=(j-1)%n+1;
					if(res<=a[u]-ans[u]){
						ans[u]+=res;
						res=0;
					}
					else{
						res-=a[u]-ans[u];
						ans[u]=a[u];
						++j;
					}
				}
			}
		}		
	}
	else{
		ans[1]=1;
		for(int i=1,j=1;i<=n;++i){
			if(t[i]){
				ans[i]=a[i]; 
				if(j<i)j=i;
				int res=a[i];
				while(res){
					if(t[(j-1)%n+1]){
						++j;
						continue;
					}
					int u=(j-1)%n+1;
					if(res<=a[u]-ans[u]){
						ans[u]+=res;
						res=0;
					}
					else{
						res-=a[u]-ans[u];
						ans[u]=a[u];
						++j;
					}
				}
			}
		}
	} 
	int zyk=1;
	ll qwq=0;
	for(int i=1;i<=n;++i){
		zyk=1LL*zyk*(((ans[i]^(1LL*i*i))+1)%mod)%mod;
	}
	printf("%d\n",zyk);
	return 0;
}