#include<bits/stdc++.h>
#define pb push_back
#define SZ(x) ((int)x.size())
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
typedef std::pair<int,int> pi;
std::vector<pi> cons(int n){
	if(n==0)return {};
	if(n%3!=2){
		std::vector<pi> ans=cons(n-1);
		ans.pb({n,n});return ans;
	}
	int a=n/3;std::vector<pi> ans;
	for(int i=0;i<a;++i)ans.pb({n-i,n-a+i+1});
	for(int i=0;i<=a;++i)ans.pb({n-a-i,n-a*2+i});
	return ans;
}
int main(){
	int n;read(n);
	std::vector<pi> ans=cons(n);
	printf("%d\n",SZ(ans));
	for(const auto &it:ans)printf("%d %d\n",it.first,it.second);
	return 0;
}