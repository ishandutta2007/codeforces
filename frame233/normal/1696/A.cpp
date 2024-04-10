#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}

int main(){
	int _;read(_);
	while(_--){
		int n,z;read(n,z);int ans=0;
		for(int i=1,x;i<=n;++i){
			read(x),ans=std::max(ans,x|z);
		}
		printf("%d\n",ans);
	}
	return 0;
}