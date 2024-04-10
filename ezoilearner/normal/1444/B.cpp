#include<bits/stdc++.h>
using namespace std;
const int Mod=998244353;
int n;
#define Maxn 300010
#define cout cerr
int fact[Maxn];
int a[Maxn];

inline void rd(int &x){
	x=0;char ch=getchar();int f=1;
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	x*=f;
}

int inv[Maxn];
int C(int i,int j){
	if(i<j)return 0;
	return 1ll*fact[i]*inv[i-j]%Mod*inv[j]%Mod;
}
int ans[Maxn];

int main(){
	rd(n);
	for(int i=1;i<=2*n;++i){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+2*n+1);
	for(int i=1;i<=2*n;++i)cout<<a[i]<<endl;
	fact[0]=1;
	for(int i=1;i<=2*n;++i)fact[i]=1ll*fact[i-1]*i%Mod;
	inv[0]=inv[1]=1;
	for(int i=2;i<=2*n;++i)inv[i]=1ll*(Mod-Mod/i)*inv[Mod%i]%Mod;
	for(int i=2;i<=2*n;++i)inv[i]=1ll*inv[i-1]*inv[i]%Mod;
	ans[0]=0;
	for(int i=1;i<=2*n;++i){
		ans[i]=ans[i-1]+C(2*n-1,n-1);if(ans[i]>=Mod)ans[i]-=Mod;
	}
	int res=0;
	for(int i=1;i<=2*n-1;++i)res=(res+1ll*(min(n-i,0)+Mod)*(a[i+1]-a[i]))%Mod;
	for(int i=1;i<=2*n-1;++i)res=(res+1ll*min(n,i)*(a[i+1]-a[i]))%Mod;
	res=1ll*res*C(2*n,n)%Mod;
	printf("%d\n",res);
	return 0;
}