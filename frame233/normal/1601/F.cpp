#include<bits/stdc++.h>
#define pb push_back
#define SZ(x) ((int)x.size())
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int B=1e6,mod1=998244353,mod2=1000000007;typedef long long ll;
std::vector<int> v[7];ll sum[7],cnt,n;int ans;
inline int norm(ll x){x%=mod1;return x<0?x+mod1:x;}
void dfs1(int dep,int val){
	++cnt,v[dep].pb(norm(cnt-val));
	if(dep==6)return;
	for(int i=0;i<10;++i)dfs1(dep+1,val*10+i);
}
void dfs2(int dep,ll val){
	if(val>n)return;
	if(dep>=1){
		if(val*B>n/10&&(val+1)*B-1<=n){
			ll tmp=val;
			for(int i=0;i<=6;++i){
				int cur=norm(cnt-tmp);
				ans=(ans+1LL*cur*SZ(v[i])+sum[i]-1LL*mod1*(v[i].end()-std::lower_bound(v[i].begin(),v[i].end(),mod1-cur)))%mod2;
				tmp*=10;
			}
			for(int i=0;i<=6;++i)cnt+=SZ(v[i]);
			return;
		}
		++cnt,ans=(ans+norm(cnt-val))%mod2;
	}
	for(int i=!dep;i<10;++i)dfs2(dep+1,10LL*val+i);
}
int main(){
	read(n),dfs1(0,0);
	for(int i=0;i<=6;++i){
		std::sort(v[i].begin(),v[i].end());
		for(auto it:v[i])sum[i]+=it;
	}
	cnt=0,dfs2(0,0);
	printf("%d\n",ans);
	return 0;
}