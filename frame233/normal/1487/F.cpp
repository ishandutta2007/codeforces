#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
template <typename _Tp>inline void chmin(_Tp &a,const _Tp &b){a=a<b?a:b;}
const int N=55,S=260,inf=0x3f3f3f3f,LIM=S/10+1,B=LIM*10+13;
char _s[N];int a[N],f[S*2+3][LIM*2+3],g[2*S+3][B*2+3];
int main(){
	scanf("%s",_s);int n=strlen(_s);for(int i=0;i<n;++i)a[i]=_s[n-1-i]-'0';
	for(int i=0;i<n;++i)a[i]*=9;
	for(int i=0;i<n;++i)if(a[i]>=10)a[i+1]+=a[i]/10,a[i]%=10;
	if(a[n])++n;
	++n,memset(f,63,sizeof(f)),f[S][LIM]=0;
	for(int i=n-1;i>=0;--i){
		memset(g,63,sizeof(g));
		for(int j=-S;j<=S;++j)for(int k=-LIM;k<=LIM;++k)g[j+S][k*10+a[i]+B]=f[j+S][k+LIM];
		for(int j=-S;j<S;++j)for(int k=-B+1;k<=B;++k)chmin(g[j+1+S][k-1+B],g[j+S][k+B]+i);
		for(int j=S;j>-S;--j)for(int k=-B;k<B;++k)chmin(g[j-1+S][k+1+B],g[j+S][k+B]+i);
		for(int j=-S;j<=S;++j)for(int k=-LIM;k<=LIM;++k)f[j+S][k+LIM]=g[j+S][k+B];
	}
	printf("%d\n",f[S][LIM]);
	return 0;
}