#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
void MAIN(){
	int n;read(n);
	for(int i=1,x;i<=n;++i)read(x);
	printf("%d\n",n/2*6);
	for(int i=1;i<n;i+=2){
		int j=i+1;
		printf("1 %d %d\n",i,j);
		printf("2 %d %d\n",i,j);
		printf("1 %d %d\n",i,j);
		printf("1 %d %d\n",i,j);
		printf("2 %d %d\n",i,j);
		printf("1 %d %d\n",i,j);
	}
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}