#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=10005;
int a[N],pre[N],suf[N];
void MAIN(){
	int n;read(n);
	for(int i=1;i<=n;++i)read(a[i]),pre[i]=std::max(pre[i-1],a[i]);
	suf[n+1]=2e9;for(int i=n;i>=1;--i)suf[i]=std::min(suf[i+1],a[i]);
	for(int i=1;i<n;++i)if(pre[i]>suf[i+1])return puts("YES"),void();
	puts("NO");
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}