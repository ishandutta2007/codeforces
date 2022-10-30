#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
int count(int n,int i){
	int ans=0;for(int j=19;j>i;--j)if(n>>j&1)ans+=1<<(j-1);
	if(n>>i&1)ans+=1<<i;else ans+=n&((1<<i)-1);
	return ans;
}
void MAIN(){
	int l,r;read(l,r);int ans=1e9;
	for(int i=0;i<20;++i){
		int cnt=count(r+1,i)-count(l,i);
		ans=std::min(ans,cnt);
	}
	printf("%d\n",ans);
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}