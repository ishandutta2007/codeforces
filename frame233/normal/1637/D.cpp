#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
template <typename _Tp>inline void chmin(_Tp &a,const _Tp &b){a=a<b?a:b;}
const int N=105;
int a[N],b[N];bool f[2*N*N],g[2*N*N];
void MAIN(){
	int n;read(n);int ans=0,ss=0;
	for(int i=1;i<=n;++i)read(a[i]),ss+=a[i]*a[i];
	for(int i=1;i<=n;++i)read(b[i]),ss+=b[i]*b[i];
	ans=ss*(n-2);int cur=0;
	memset(f,0,sizeof(f)),f[0]=1;
	for(int i=1;i<=n;++i){
		memset(g,0,cur+a[i]+b[i]+3);
		for(int j=cur;j>=0;--j)g[j+a[i]]|=f[j],g[j+b[i]]|=f[j];
		cur+=a[i]+b[i],memcpy(f,g,cur+3);
	}
	int res=1e9;
	for(int i=0;i<=cur;++i)if(f[i])chmin(res,i*i+(cur-i)*(cur-i));
	printf("%d\n",ans+res);
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}