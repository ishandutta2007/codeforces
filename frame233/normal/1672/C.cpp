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
	int n;read(n);int c=0;
	for(int i=1;i<=n;++i)read(a[i]);
	for(int i=1;i<n;++i)c+=a[i]==a[i+1];
	if(c<=1)return puts("0"),void();
	int fir=-1,las=-1;
	for(int i=1;i<n;++i)if(a[i]==a[i+1])fir=fir==-1?i:fir,las=i;
	printf("%d\n",std::max(1,las-fir-1));
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}