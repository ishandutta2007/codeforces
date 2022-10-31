#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=200005;
int a[N],b[N],cnt[N];
void MAIN(){
	int n;read(n);memset(cnt,0,(n+3)<<2);
	for(int i=1;i<=n;++i)read(a[i]);
	for(int i=1;i<=n;++i)read(b[i]);
	for(int i=n,j=n;i>=1;--i){
		if(a[i]==b[j]){
			--j;while(b[j]==a[i])++cnt[b[j--]];
			continue;
		}
		if(!cnt[a[i]])return puts("NO"),void();
		--cnt[a[i]];
	}
	puts("YES");
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}