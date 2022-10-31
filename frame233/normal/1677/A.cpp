#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=5005;
int a[N],b[N][N],c[N][N];
void MAIN(){
	int n;read(n);
	for(int i=1;i<=n;++i)read(a[i]);
	for(int i=0;i<=n+1;++i)for(int j=0;j<=n+1;++j)b[i][j]=c[i][j]=0;
	for(int j=1;j<=n;++j)for(int i=1;i<=n;++i)c[j][i]=c[j][i-1]+(a[i]<a[j]);
	for(int j=1;j<=n;++j)for(int i=n;i>=1;--i)b[j][i]=b[j][i+1]+(a[i]<a[j]);
	long long ans=0;
	for(int i=1;i<=n;++i)for(int j=i+1;j<=n;++j)ans+=1LL*c[j][i-1]*b[i][j+1];
	printf("%lld\n",ans);
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}