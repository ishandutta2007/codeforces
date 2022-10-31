#include<bits/stdc++.h>
#define pb push_back
#define SZ(x) ((int)x.size())
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=100005;typedef std::pair<int,int> pi;typedef long long ll;
int pre1[N],pre2[N],suf1[N],suf2[N];
ll solve(std::vector<pi> vec){
	for(auto &&it:vec)std::tie(it.first,it.second)=pi{(it.first+it.second)/2,(it.first-it.second)/2};
	std::sort(vec.begin(),vec.end());
	for(int i=0,mn=1e9,mx=-1e9;i<SZ(vec);++i){
		mn=std::min(mn,vec[i].second),mx=std::max(mx,vec[i].second);
		pre1[i]=mn,pre2[i]=mx;
	}
	for(int i=SZ(vec)-1,mn=1e9,mx=-1e9;i>=0;--i){
		mn=std::min(mn,vec[i].second),mx=std::max(mx,vec[i].second);
		suf1[i]=mn,suf2[i]=mx;
	}
	ll ans=0;for(int i=0;i+1<SZ(vec);++i)ans+=1LL*(vec[i+1].first-vec[i].first)*std::max(0,std::min(pre2[i],suf2[i+1])-std::max(pre1[i],suf1[i+1]));
	return ans;
}
int main(){
	int n;read(n);std::vector<pi> A,B;
	for(int i=1,x,y;i<=n;++i){read(x,y);if((x+y)%2)A.pb({x+1,y});else B.pb({x,y});}
	printf("%lld\n",solve(A)+solve(B));
	return 0;
}