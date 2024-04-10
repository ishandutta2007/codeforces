#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=1000005;
int sum[N],a[N];bool is[N];
void MAIN(){
	int n,c;read(n,c),memset(sum,0,(c+3)<<2);memset(is,0,(c+3));
	for(int i=1;i<=n;++i)read(a[i]),++sum[a[i]],is[a[i]]=1;
	for(int i=1;i<=c;++i)sum[i]+=sum[i-1];
	for(int i=1;i<=c;++i)if(is[i]){
		for(int j=i,t=1;j<=c;j+=i,++t){
			if(sum[std::min(c,j+i-1)]!=sum[j-1]){
				if(!is[t]){
					return puts("No"),void();
				}
			}
		}
	}
	puts("Yes");
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}