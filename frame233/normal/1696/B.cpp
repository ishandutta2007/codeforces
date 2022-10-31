#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
int a[100005];
void MAIN(){
	int n;read(n);
	for(int i=1;i<=n;++i)read(a[i]);
	if(std::count(a+1,a+n+1,0)==n)puts("0");
	else{
		int p=1,q=n;while(a[p]==0)++p;
		while(a[q]==0)--q;
		if(std::count(a+p,a+q+1,0)==0)puts("1");else puts("2");
	}
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}