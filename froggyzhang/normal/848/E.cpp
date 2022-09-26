#include<bits/stdc++.h>
using namespace std;
#define N 1000010
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
int n,f[N];
const int a[16]={0,4,8,-1,16,-10,4,-12,-48,26,-44,15,-16,-4,-4,-1};
const int b[16]={0,0,0,24,4,240,204,1316,2988,6720,26200,50248,174280,436904,1140888,3436404};
int main(){
	n=read();
	for(int i=0;i<16&&i<=n;++i){
		f[i]=b[i];
	}
	for(int i=16;i<=n;++i){
		f[i]=0;
		for(int j=0;j<16;++j){
			f[i]=(f[i]+1LL*a[j]*f[i-j-1])%mod;
		}
	}
	printf("%d\n",(f[n]+mod)%mod);
	return 0;
}