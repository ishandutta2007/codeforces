#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
void MAIN(){
	int n,k;read(n,k);
	if(n==4&&k==3)return puts("-1"),void();
	if(k==n-1){
		printf("%d %d\n",1,3);
		printf("%d %d\n",n-2,n-1);
		for(int i=2;i<n/2;++i)if(i!=3)printf("%d %d\n",i,n-i-1);
		printf("%d %d\n",0,n-4);
	}
	else{
		if(k==0){
			for(int i=0;i<n/2;++i)printf("%d %d\n",i,n-i-1);
			return;
		}
		printf("%d %d\n",k,n-1);
		for(int i=0;i<n/2;++i)if(i!=k&&i!=n-1&&n-i-1!=k&&n-i-1!=n-1)printf("%d %d\n",i,n-i-1);
		printf("%d %d\n",0,n-k-1);
	}
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}