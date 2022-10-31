#include<bits/stdc++.h>
#define pb push_back
#define SZ(x) ((int)x.size())
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=100005;
std::vector<int> all[N],e[N],VEC[N],leaf[N];char ans[N];int dep[N],mxd,sum[N],cnt[N];bool mark[N],used[N];
void dfs(int x,int fa){
	dep[x]=dep[fa]+1,++sum[dep[x]],mxd=std::max(mxd,dep[x]),VEC[dep[x]].pb(x);
	if(e[x].empty())leaf[dep[x]].pb(x);
	for(auto v:e[x])dfs(v,x);
}
int main(){
	int n,x;read(n,x);
	for(int i=2,x;i<=n;++i)read(x),e[x].pb(i);
	dfs(1,0);for(int i=1;i<=mxd;++i)++cnt[sum[i]],all[sum[i]].pb(i);
	std::bitset<N> dp;dp.set(0);
	std::vector<std::bitset<N>> vec={dp};std::vector<int> v={-1},lim={-1};
	for(int i=1;i<=n;++i)if(cnt[i]){
		int t=1,r=cnt[i];
		while(r>t)dp|=dp<<(t*i),r-=t,t<<=1;
		dp|=dp<<(r*i),vec.pb(dp),v.pb(i),lim.pb(cnt[i]);
	}
	if(dp.test(x)){
		int cur=x;
		for(int i=SZ(vec)-1;i>0;--i){
			for(int j=0;j<=lim[i];++j){
				int to=cur-j*v[i];
				if(to>=0&&vec[i-1].test(to)){
					for(int k=0;k<j;++k)mark[all[v[i]][k]]=1;
					cur=to;break;
				}
			}
		}
		for(int i=1;i<=n;++i)ans[i]=mark[dep[i]]?'a':'b';
		printf("%d\n",mxd);
	}
	else{
		printf("%d\n",mxd+1),std::fill(ans+1,ans+n+1,'b');
		for(int i=1;i<=mxd;++i)if(x>=SZ(VEC[i])){used[i]=1;for(auto it:VEC[i])ans[it]='a',--x;}
		for(int i=1;i<=mxd&&x;++i)if(!used[i]&&x<=SZ(leaf[i]))for(auto it:leaf[i]){ans[it]='a',--x;if(!x)break;}
	}
	printf("%s\n",ans+1);
	return 0;
}