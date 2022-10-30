#include<bits/stdc++.h>
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
#define SZ(x) ((int)x.size())
#define pb push_back
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=505;
int a[N+N][N],cnt[N],n;
bool used[N+N],mark[N][N];std::vector<int> ans;
void solve(int x){
	used[x]=true,ans.pb(x);
	for(int i=1;i<=n+n;++i)if(!used[i])for(int j=1;j<=n;++j)if(a[x][j]==a[i][j]){used[i]=true;break;}
	for(int i=1;i<=n;++i)mark[i][a[x][i]]=true;
}
bool check(){
	for(int i=1;i<=n;++i){
		memset(cnt,0,(n+3)<<2);
		for(int j=1;j<=n+n;++j)if(!used[j])++cnt[a[j][i]];
		for(int j=1;j<=n;++j)if(cnt[j]==1&&!mark[i][j]){
			for(int k=1;k<=n+n;++k)if(!used[k]&&a[k][i]==j)return solve(k),true;
		}
	}
	return false;
}
void MAIN(){
	read(n);memset(used,0,sizeof(used)),memset(mark,0,sizeof(mark));
	for(int i=1;i<=n+n;++i)for(int j=1;j<=n;++j)read(a[i][j]);
	ans.clear();int res=1;
	while(SZ(ans)<n){
		if(!check()){
			res=(res+res)%998244353;
			for(int i=1;i<=n+n;++i)if(!used[i]){solve(i);break;}
		}
	}
	std::sort(ans.begin(),ans.end());
	printf("%d\n",res);for(auto it:ans)printf("%d ",it);
	printf("\n");
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}