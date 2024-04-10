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
	int n,m;read(n,m);memset(a,0,(n+3)<<2);
	for(int i=1,x,y,z;i<=m;++i)read(x,y,z),a[y]=1;
	for(int i=1;i<=n;++i)if(!a[i]){
		for(int j=1;j<=n;++j)if(i!=j){
			printf("%d %d\n",i,j);
		}
		return;
	}
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}