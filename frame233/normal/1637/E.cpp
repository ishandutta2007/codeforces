#include<bits/stdc++.h>
#define pb push_back
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=300005,B=550;typedef long long ll;
int a[N],t[N],pos,cnt[N];std::vector<int> v[N],b[B+5];bool mark[N];
void MAIN(){
	for(int i=1;i<=B;++i)b[i].clear();
	int n,m;read(n,m);
	for(int i=1;i<=n;++i)read(a[i]),t[i]=a[i];
	std::sort(t+1,t+n+1),pos=std::unique(t+1,t+n+1)-t-1;
	for(int i=1;i<=pos;++i)v[i].clear(),cnt[i]=0;
	for(int i=1;i<=n;++i)a[i]=std::lower_bound(t+1,t+pos+1,a[i])-t,++cnt[a[i]];
	for(int i=1,x,y;i<=m;++i){
		read(x,y),x=std::lower_bound(t+1,t+pos+1,x)-t,y=std::lower_bound(t+1,t+pos+1,y)-t;
		v[x].pb(y),v[y].pb(x);
	}
	ll ans=0;
	for(int i=1;i<=pos;++i)if(cnt[i]>B){
		for(auto it:v[i])mark[it]=1;
		for(int j=1;j<=pos;++j)if(i!=j&&!mark[j]){
			ans=std::max(1LL*(cnt[i]+cnt[j])*(t[i]+t[j]),ans);
		}
		for(auto it:v[i])mark[it]=0;
	}
	for(int i=1;i<=pos;++i)if(cnt[i]<=B)b[cnt[i]].pb(i);
	for(int i=1;i<=B;++i)std::sort(b[i].begin(),b[i].end(),std::greater<int>());
	for(int i=1;i<=pos;++i)if(cnt[i]<=B){
		for(auto it:v[i])mark[it]=1;
		for(int j=1;j<=B;++j){
			for(auto it:b[j])if(!mark[it]&&it!=i){
				ans=std::max(1LL*(cnt[i]+j)*(t[i]+t[it]),ans);
				break;
			}
		}
		for(auto it:v[i])mark[it]=0;
	}
	printf("%lld\n",ans);
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}