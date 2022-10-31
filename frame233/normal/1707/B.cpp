#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=100005;
int a[N];
void MAIN(){
	int n;read(n);
	for(int i=1;i<=n;++i)read(a[i]);
	for(int i=1,p=1;i<n;++i){
		p=std::max(p,i);for(int j=n;j>p;--j)a[j]=a[j]-a[j-1];
		std::sort(a+p+1,a+n+1);while(p<n&&a[p+1]==0)++p;
	}
	printf("%d\n",a[n]);
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}