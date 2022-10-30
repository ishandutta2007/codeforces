#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=200005;
int a[N],c[N];
void MAIN(){
	int n,k;read(n,k);memset(c,0,(n+3)<<2);
	for(int i=1;i<=n;++i)read(a[i]),++c[a[i]];
	int cur=-n,ans=1e9,l=-1,r=-1;
	for(int x=1,y=0;x<=n;++x){
		while(y<n&&cur<k)cur+=2*c[++y];
		if(cur>=k&&y-x<ans)ans=y-x,l=x,r=y;
		cur-=2*c[x];
	}
	printf("%d %d\n",l,r),cur=0;int tar=1,last=1;
	for(int i=1;i<=n;++i){
		cur+=l<=a[i]&&a[i]<=r?1:-1;
		if(tar==k?i==n:cur==tar)printf("%d %d\n",last,i),last=i+1,++tar;
	}
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}