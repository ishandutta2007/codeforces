#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
void MAIN(){
	int n,k;read(n,k);
	if(k>(n+1)/2)return puts("-1"),void();
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			if(i==j&&i%2&&k)printf("R"),--k;
			else printf(".");
		}
		printf("\n");
	}
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}