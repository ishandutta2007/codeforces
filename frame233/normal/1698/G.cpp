#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
typedef long long ll;typedef __int128 LL;
char S[37];ll P;int n;
ll mul(ll a,ll b){
	LL c=0;for(int i=0;i<n;++i)if(a>>i&1)c^=(LL)b<<i;
	for(int i=n+n-2;i>=n;--i)if(c>>i&1)c^=(LL)P<<(i-n);
	return c;
}
std::map<ll,int> mp;
int main(){
	ll s=0;scanf("%s",S);int n=strlen(S);
	for(int i=0;i<n;++i)if(S[i]=='1')s|=1LL<<i;
	if(s==0)return puts("-1"),0;
	int p=1;while(s%2==0)s/=2,++p;
	P=s,::n=63-__builtin_clzll(s);
	ll cur=1,tmp=1;for(int i=0;i<1<<17;++i)mp[cur]=i,cur=mul(cur,2);
	for(int i=1;i<=1<<18;++i){
		tmp=mul(tmp,cur);auto it=mp.find(tmp);
		if(it!=mp.end())return printf("%d %lld\n",p,p+((ll)i<<17)-it->second),0;
	}
	return 0;
}