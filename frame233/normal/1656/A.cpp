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
	int mn=std::min_element(a+1,a+n+1)-a,mx=std::max_element(a+1,a+n+1)-a;
	printf("%d %d\n",mn,mx);
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}