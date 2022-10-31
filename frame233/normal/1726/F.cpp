#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch=getchar();bool f=false;while(!isdigit(ch))f|=ch=='-',ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=200005;typedef long long ll;
ll l[N],r[N],d[N];
int main(){
	int n,t;read(n,t);
	auto norm=[&](ll x){return (x%t+t)%t;};
	for(int i=1,g,c;i<=n;++i)read(g,c),l[i]=norm(-c),r[i]=norm(g-c);
	for(int i=1;i<n;++i)read(d[i]),d[i]+=d[i-1];
	std::map<int,ll> dp;for(int i=1;i<=n;++i)l[i]=norm(l[i]-d[i-1]),r[i]=norm(r[i]-d[i-1]),dp[l[i]]=dp[norm(r[i]-1)]=0;
	auto get=[&](int x){auto it=dp.find(x);return it==dp.end()?1e18:it->second;};
	for(int i=1;i<=n;++i){
		if(l[i]<=r[i]){
			ll mn=get(l[i]);for(auto it=dp.lower_bound(r[i]);it!=dp.end();it=dp.erase(it))mn=std::min(mn,it->second+(t-it->first)+l[i]);
			for(auto it2=dp.begin();it2!=dp.end()&&it2->first<l[i];it2=dp.erase(it2))mn=std::min(mn,it2->second+l[i]-it2->first);
			dp[l[i]]=mn;
		}
		else{
			ll mn=get(l[i]);for(auto it2=dp.lower_bound(r[i]);it2!=dp.end()&&it2->first<l[i];it2=dp.erase(it2))mn=std::min(mn,it2->second+l[i]-it2->first);
			dp[l[i]]=mn;
		}
	}
	ll mn=1e18;for(const auto &it:dp)mn=std::min(mn,it.second);
	printf("%lld\n",mn+d[n-1]);
	return 0;
}