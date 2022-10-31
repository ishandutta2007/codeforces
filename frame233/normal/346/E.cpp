#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
int solve(int a,int n,int p){
	if(1LL*a*n<p)return std::max(a,p-a*n);
	return solve(std::min(p%a,a-p%a),1LL*a*n/p-(1LL*a*n%p<(p/a-1)*a),a);
}
int main(){
	int _;read(_);
	while(_--){
		int a,n,p,h;read(a,n,p,h),a%=p;
		if(1LL*a*n<p)puts(a<=h?"YES":"NO");
		else puts(solve(a,n,p)<=h?"YES":"NO");
	}
	return 0;
}