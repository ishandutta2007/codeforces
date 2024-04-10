#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=200005;
int cnt[35];bool can[N];
void MAIN(){
	int n;read(n);int x;
	memset(cnt,0,sizeof(cnt));
	for(int i=1;i<=n;++i){
		read(x);
		for(int j=0;j<30;++j)if(x>>j&1)++cnt[j];
	}
	memset(can,1,n+3);
	for(int i=0;i<30;++i){
		for(int j=1;j<=n;++j)if(cnt[i]%j)can[j]=0;
	}
	for(int i=1;i<=n;++i)if(can[i])printf("%d ",i);
	printf("\n");
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}