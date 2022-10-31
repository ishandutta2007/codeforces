#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=200005;
int a[N];
void MAIN(){
	int n,x;read(n,x),x*=2;
	for(int i=1;i<=n;++i)read(a[i]);
	int ans=-1;
	for(int i=1;i<=n;++i){
		int j=i,mn=a[i],mx=a[i];
		while(j<=n&&mx-mn<=x)++j,mx=std::max(mx,a[j]),mn=std::min(mn,a[j]);
		++ans,i=j-1;
	}
	printf("%d\n",ans);
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}