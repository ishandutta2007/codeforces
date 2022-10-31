#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
typedef long long ll;
void MAIN(){
	ll x;read(x);
	if((x&(x-1))==0)return puts("-1"),void();
	if(x%2)return puts("2"),void();
	ll y=2;while(x%2==0)x/=2,y*=2;
	printf("%lld\n",std::min(x,y));
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}