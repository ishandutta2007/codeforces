#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int mod=998244353;
#define N 100010
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
int n,a[N],cnt[12],pw[22],ans;
void Split(int x){
	int p=0;
	while(x)++p,x/=10;
	++cnt[p];
}
int Get(int x){
	static int t[12];
	int len=0;
	while(x){
		t[++len]=x%10;
		x/=10;
	}
	int tot=0;
	for(int i=1;i<=len;++i){
		for(int j=1;j<=10;++j){
			tot=(tot+1LL*pw[min(i+j,i<<1)-1]*t[i]%mod*cnt[j])%mod;
			tot=(tot+1LL*pw[min(i+j,(i<<1)-1)-1]*t[i]%mod*cnt[j])%mod;
		}
	}
	return tot;
}
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
		Split(a[i]);
	}
	pw[0]=1;
	for(int i=1;i<=20;++i){
		pw[i]=pw[i-1]*10LL%mod;
	}
	for(int i=1;i<=n;++i){
		ans=(ans+Get(a[i]))%mod;
	}
	printf("%d\n",ans);
	return 0;
}