#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=305;
int a[N],t[N],v[N];
void MAIN(){
	int n,m;read(n,m);
	for(int i=1;i<=m;++i)read(a[i]),t[i]=i;
	std::sort(t+1,t+m+1,[&](int x,int y){return a[x]==a[y]?x>y:a[x]<a[y];});
	for(int i=1;i<=m;++i)v[t[i]]=i;
	int ans=0;for(int i=1;i<=m;++i)for(int j=i+1;j<=m;++j)if(v[i]<v[j])++ans;
	printf("%d\n",ans);
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}