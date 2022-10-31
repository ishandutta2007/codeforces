#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
template <typename _Tp>inline bool chmin(_Tp &a,const _Tp &b){if(a>b)return a=b,1;return 0;}
const int N=1000005;
int a[N],f[N][2],pre[N][2];
void MAIN(){
	int n;read(n);
	for(int i=1;i<=n;++i)read(a[i]);
	memset(f,63,(n+3)*8),f[1][0]=-1e9,f[1][1]=-1e9;
	for(int i=2;i<=n;++i){
		for(int l=0;l<2;++l){
			int last=l?a[i-1]:-a[i-1];
			for(int t=0;t<2;++t){
				int v=t?a[i]:-a[i];
				if(v>f[i-1][l]&&chmin(f[i][t],last))pre[i][t]=l;
				if(v>last&&chmin(f[i][t],f[i-1][l]))pre[i][t]=l;
			}
		}
	}
	if(f[n][0]>=1e9&&f[n][1]>=1e9)return puts("NO"),void();
	puts("YES");for(int i=n,j=f[n][0]<1e9?0:1;i>=1;--i)a[i]=j?a[i]:-a[i],j=pre[i][j];
	for(int i=1;i<=n;++i)printf("%d%c",a[i]," \n"[i==n]);
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}