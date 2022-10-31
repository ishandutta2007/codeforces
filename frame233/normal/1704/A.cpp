#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=55;
char a[N],b[N];
void MAIN(){
	int n,m;read(n,m);scanf("%s%s",a+1,b+1);
	bool flag=1;for(int i=2;i<=m;++i)flag&=a[n-m+i]==b[i];
	if(!flag)puts("NO");
	else{
		char x=a[1],y=a[1];
		for(int i=1;i<=n-m+1;++i)x=std::min(x,a[i]),y=std::max(y,a[i]);
		if(x==b[1]||y==b[1])puts("YES");else puts("NO");
	}
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}