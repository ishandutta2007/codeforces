#include<bits/stdc++.h>
#define pb push_back
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=200005;
int n,m,a[N],b[N];
inline int getid(int x,int y){return (x-1)*m+y;}
void MAIN(){
	read(n,m);for(int i=1;i<=n*m;++i)read(a[i]);
	for(int i=1;i<=n;++i){
		if(std::is_sorted(a+getid(i,1),a+getid(i,m)+1))continue;
		for(int j=1;j<=m;++j)b[j]=a[getid(i,j)];
		std::sort(b+1,b+m+1);int fir=-1,las=-1;
		for(int j=1;j<=m;++j){
			if(a[getid(i,j)]!=b[j]){
				if(fir==-1)fir=j;
				las=j;
			}
		}
		for(int i=1;i<=n;++i)std::swap(a[getid(i,fir)],a[getid(i,las)]);
		bool flag=1;for(int i=1;i<=n;++i)flag&=std::is_sorted(a+getid(i,1),a+getid(i,m)+1);
		if(flag)printf("%d %d\n",fir,las);
		else puts("-1");
		return;
	}
	printf("%d %d\n",1,1);
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}