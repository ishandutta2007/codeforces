#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
template <typename _Tp>inline _Tp abs(const _Tp &a){return a>=0?a:-a;}
const int N=100005;
char s[N],t[N];
void MAIN(){
	int n;scanf("%d%s%s",&n,s+1,t+1);
	int cnt=std::count(s+1,s+n+1,'1');
	bool flag=1;for(int i=1;i<=n;++i)flag&=s[i]==t[i];
	if(flag)return puts("0"),void();
	if(cnt==0)return puts("-1"),void();
	if(cnt==n)return puts(std::count(t+1,t+n+1,'1')==1?"1":"-1"),void();
	int ans=1e9;
	for(int o=0;o<2;++o){
		if(o)for(int i=1;i<=n;++i)t[i]^=1;
		int tmp=-1,c0=0,c1=0;for(int i=1;i<=n;++i)if(s[i]!=t[i])++(s[i]=='1'?c1:c0);
		if(c0==c1||c1==c0+1)tmp=c0+c1;
		if(tmp%2==o)ans=std::min(ans,tmp);
	}
	printf("%d\n",ans>=1e9?-1:ans);
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}