#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=500005;typedef long long ll;typedef __int128 LL;
int a[N],b[N];ll d[N];
int main(){
	int n,c;read(n,c);
	for(int i=1;i<=n;++i)read(a[i]);
	LL cur=0;for(int i=1;i<=n;++i)read(b[i]),cur+=b[i];
	for(int i=1;i<=n;++i)d[i]=a[i]+1LL*(i-1)*c-b[i];
	std::sort(d+1,d+n+1);ll ans=cur;
	for(int i=1;i<=n;++i){
		cur+=d[i];LL tmp=cur-(LL)c*(i-1)*i/2;
		if(tmp<ans)ans=tmp;
	}
	printf("%lld\n",ans);
	return 0;
}