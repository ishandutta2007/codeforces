#include<bits/stdc++.h>
#define pb push_back
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=200005;typedef std::pair<int,int> pi;typedef long long ll;
int n,m,a[N],k[N],pre[N],nxt[N],res[N];ll s[N];
std::vector<pi> vec[N];
inline void push(int i){
	int t=(s[i]-s[pre[i]]-1)/(i-pre[i]);
	vec[std::upper_bound(k+1,k+m+1,t)-k-1].pb({i,pre[i]});
}
int main(){
	read(n,m);
	for(int i=1;i<=n;++i)read(a[i]),s[i]=s[i-1]+a[i];
	for(int i=1;i<=m;++i)read(k[i]);
	for(int i=1;i<=n;++i)pre[i]=i-1,nxt[i-1]=i;
	for(int i=1;i<n;++i)push(i);
	int ans=0;
	for(int i=m,x,p,s;i>=1;--i){
		while(!vec[i].empty()){
			std::tie(x,p)=vec[i].back();vec[i].pop_back();if(pre[x]!=p)continue;
			s=nxt[x],pre[s]=p,nxt[p]=s,ans=std::max(ans,s-p-1);if(s!=n)push(s);
		}
		res[i]=ans;
	}
	for(int i=1;i<=m;++i)printf("%d%c",res[i]," \n"[i==m]);
	return 0;
}