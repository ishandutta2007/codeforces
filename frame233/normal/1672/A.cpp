#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=55;
int a[N];
void MAIN(){
	int n;read(n);int s=0;
	for(int i=1;i<=n;++i)read(a[i]),s+=a[i];
	puts((s-n)%2?"errorgorn":"maomao90");
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}