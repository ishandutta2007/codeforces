#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=75;
int a[N];
void MAIN(){
	int n;read(n);int ans=n-1;for(int i=1;i<=n;++i)read(a[i]);
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j){
			int cnt=0;
			for(int k=1;k<=n;++k){
				if((a[k]-a[i])*(j-i)!=(k-i)*(a[j]-a[i]))++cnt;
			}
			ans=std::min(ans,cnt);
		}
	}
	printf("%d\n",ans);
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}