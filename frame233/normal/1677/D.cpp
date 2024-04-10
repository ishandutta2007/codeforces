#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=1000005,mod=998244353;
int a[N];
void MAIN(){
	int n,k;read(n,k);
	for(int i=1;i<=n;++i)read(a[i]);
	bool flag=1;for(int i=0;i<k;++i)flag&=a[n-i]<=0;
	if(!flag)return puts("0"),void();
	int ans=1;
	for(int i=1;i<=n-k;++i){
		if(a[i]==-1)ans=1LL*ans*(i+k)%mod;
		else if(a[i]==0)ans=1LL*ans*(k+1)%mod;
	}
	for(int j=1;j<=k;++j)ans=1LL*ans*j%mod;
	printf("%d\n",ans);
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}