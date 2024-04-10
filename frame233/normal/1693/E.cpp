#include<bits/stdc++.h>
#define pb push_back
#define lowbit(x) ((x)&(-(x)))
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=200005;
int a[N];std::vector<int> vec[N];
int c[N];void add(int x,int C){for(;x<N;x+=lowbit(x))c[x]+=C;}
int ask(int x){int ans=0;for(;x;x-=lowbit(x))ans+=c[x];return ans;}
int main(){
	int n;read(n);for(int i=1;i<=n;++i)read(a[i]),vec[a[i]].pb(i);
	int p1=0,p2=n+1;long long ans=0;
	for(int i=n;i>=1;--i)if(!vec[i].empty()){
		for(auto it:vec[i])add(it,1);
		int r=std::max(p1,vec[i].back()),l=std::min(p2,vec[i][0]);
		ans+=ask(r)-ask(l-1),p1=l-1,p2=r+1;
	}
	printf("%lld\n",ans);
	return 0;
}