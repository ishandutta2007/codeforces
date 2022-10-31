#include<bits/stdc++.h>
#define pb push_back
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
template <typename _Tp>inline void chmax(_Tp &a,const _Tp &b){a=a<b?b:a;}
const int N=200005;
int a[N],t[N],d[N],cnt[N];
std::vector<int> vec[N],Q1[N],Q2[N],Q3[N];
void MAIN(){
	int n,m;read(n,m);
	for(int i=0;i<=n+1;++i)vec[i].clear(),Q1[i].clear(),Q2[i].clear(),Q3[i].clear();
	for(int i=1;i<=n;++i)read(a[i]),t[i]=a[i];
	std::sort(t+1,t+n+1);int pos=std::unique(t+1,t+n+1)-t-1;
	for(int i=1;i<=n;++i)a[i]=std::lower_bound(t+1,t+pos+1,a[i])-t,vec[a[i]].pb(i);
	memset(d,0,(n+3)<<2),memset(cnt,0,(n+3)<<2);
	for(int i=1,l,r;i<=m;++i)read(l,r),chmax(d[l],r),Q1[r].pb(l),Q2[l].pb(r);
	int limr=1,liml=n;bool flag=0;
	for(int i=1,p=1;i<=n;++i){
		++cnt[a[i]];while(cnt[a[i]]>1)--cnt[a[p++]];
		for(auto it:Q1[i])if(it<p)limr=std::max(limr,p-1),flag=1;
	}
	if(!flag)return puts("0"),void();
	memset(cnt,0,(n+3)<<2);
	for(int i=n,p=n;i>=1;--i){
		++cnt[a[i]];while(cnt[a[i]]>1)--cnt[a[p--]];
		for(auto it:Q2[i])if(it>p)liml=std::min(liml,p+1);
	}
	for(int i=1;i<=n;++i)chmax(d[i],d[i-1]);
	for(int i=1;i<=n;++i){
		int r=d[i];if(r<i)continue;
		auto it=--upper_bound(vec[a[i]].begin(),vec[a[i]].end(),r);
		Q3[i+1].pb(*it);
	}
	int ans=1e9;
	for(int i=1;i<=liml;++i){
		for(auto it:Q3[i])limr=std::max(limr,it);
		ans=std::min(ans,limr-i+1);
	}
	printf("%d\n",ans);
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}