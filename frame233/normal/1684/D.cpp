#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=200005;typedef long long ll;
int t[N],a[N];bool mark[N];
void MAIN(){
	int n,k;read(n,k);memset(mark,0,n+3);
	for(int i=1;i<=n;++i)read(a[i]),t[i]=i;
	std::sort(t+1,t+n+1,[&](int x,int y){return a[x]+x>a[y]+y;});
	for(int i=1;i<=k;++i)mark[t[i]]=1;
	int c=0;ll tot=0;
	for(int i=1;i<=n;++i){
		if(mark[i])++c;
		else tot+=a[i]+c;
	}
	printf("%lld\n",tot);
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}