#include<bits/stdc++.h>
#define SZ(x) ((int)x.size())
#define pb push_back
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
void MAIN(){
	int a,b;read(a,b);
	int tmp=(a+b)/2;
	std::vector<int> v;
	for(int i=std::max(tmp-b,0);i<=a&&i<=tmp;++i)if(2*i+b-tmp>=0&&2*i+b-tmp<=a+b)v.pb(2*i+b-tmp);
	std::swap(a,b);
	for(int i=std::max(tmp-b,0);i<=a&&i<=tmp;++i)if(2*i+b-tmp>=0&&2*i+b-tmp<=a+b)v.pb(2*i+b-tmp);
	std::sort(v.begin(),v.end()),v.erase(std::unique(v.begin(),v.end()),v.end());
	printf("%d\n",SZ(v));
	for(auto it:v)printf("%d ",it);
	printf("\n");
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}