#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=100005;
int a[N],b[N],cnt[N];
void MAIN(){
	memset(cnt,0,sizeof(cnt));
	int n;read(n);
	for(int i=1;i<=n;++i)read(a[i]),b[i]=a[i];
	std::sort(b+1,b+n+1);
	for(int i=1;i<=n;++i)cnt[a[i]]+=i&1?1:-1;
	for(int i=1;i<=n;++i)cnt[b[i]]-=i&1?1:-1;
	for(int i=1;i<=100000;++i)if(cnt[i])return puts("NO"),void();
	puts("YES");
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}