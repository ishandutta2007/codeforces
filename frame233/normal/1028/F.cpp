#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return !b?a:gcd(b,a%b);}
typedef std::pair<int,int> pi;typedef long long ll;
std::map<int,std::set<pi>> mp;
std::map<pi,int> ans;
inline void upd(int a,int b,int C){
	int g=gcd(a,b);a/=g,b/=g;
	ans[{a,b}]+=C;
}
int main(){
	int q;read(q);
	int opt,x,y,cnt=0;
	while(q--){
		read(opt,x,y);
		if(opt==1){
			ll z=1LL*x*x+1LL*y*y;
			for(auto it:mp[z])upd(x+it.first,y+it.second,2);
			upd(x+x,y+y,1),mp[z].insert({x,y}),++cnt;
		}
		else if(opt==2){
			ll z=1LL*x*x+1LL*y*y;mp[z].erase({x,y}),--cnt,upd(x+x,y+y,-1);
			for(auto it:mp[z])upd(x+it.first,y+it.second,-2);
		}
		else{
			int g=gcd(x,y);x/=g,y/=g;
			printf("%d\n",cnt-ans[{x,y}]);
		}
	}
	return 0;
}