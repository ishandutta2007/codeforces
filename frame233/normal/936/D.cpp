#include<bits/stdc++.h>
#define pb push_back
#define SZ(x) ((int)x.size())
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
template <typename _Tp>inline void chmax(_Tp &a,const _Tp &b){a=a<b?b:a;}
const int N=3000005;typedef std::pair<int,int> pi;
int f[N][2],g[N][2],A[N],B[N],t[N],pos;
bool is[N][2];int nxt[N][2];std::set<int> S[2];
int main(){
	int n,a,b,T;read(n,a,b,T);
	for(int i=1;i<=a;++i)read(A[i]),t[++pos]=A[i]-1,t[++pos]=A[i],t[++pos]=A[i]+1;
	for(int i=1;i<=b;++i)read(B[i]),t[++pos]=B[i]-1,t[++pos]=B[i],t[++pos]=B[i]+1;
	t[++pos]=0,t[++pos]=n+1,std::sort(t+1,t+pos+1),pos=std::unique(t+1,t+pos+1)-t-1;
	for(int i=1;i<=a;++i)is[std::lower_bound(t+1,t+pos+1,A[i])-t][0]=1;
	for(int i=1;i<=b;++i)is[std::lower_bound(t+1,t+pos+1,B[i])-t][1]=1;
	for(int i=1;i<=pos;++i)for(int j=0;j<2;++j)if(is[i][j])S[j].insert(i);
	memset(f,-63,sizeof(f)),f[1][0]=f[1][1]=0;
	for(int i=2;i<=pos;++i){
		for(int j=0;j<2;++j){
			if(is[i][j]&&f[i-1][j]>=T)f[i][j]=f[i-1][j]-T+t[i]-t[i-1],g[i][j]=0;
			else if(!is[i][j])f[i][j]=f[i-1][j]+t[i]-t[i-1],g[i][j]=0;
		}
		int tmp=std::min(T,f[i][0]);if(!is[i][1]&&f[i][1]<tmp)f[i][1]=tmp,g[i][1]=1;
		tmp=std::min(T,f[i][1]);if(!is[i][0]&&f[i][0]<tmp)f[i][0]=tmp,g[i][0]=1;
	}
	if(f[pos][0]<0&&f[pos][1]<0)return puts("No"),0;
	int cur=pos,j=f[pos][0]>=0?0:1;std::vector<int> all;
	while(cur>1){
		if(g[cur][j]==1)all.pb(cur),j^=1;
		else --cur;
	}
	if(j==1)all.pb(1);
	std::reverse(all.begin(),all.end());std::vector<pi> res;
	j=0;int p=0,rest=0;
	for(int i=1;i<=pos;++i){
		if(p<SZ(all)&&all[p]==i)++p,j^=1;
		if(rest>=T){
			auto it=S[j].upper_bound(i);
			if(it!=S[j].end()&&(p==SZ(all)||*it<=all[p]))S[j].erase(it),rest-=T,res.pb({t[i],j});
		}
		int cur=t[i]+T-rest;rest+=t[i+1]-t[i]-1;
		while(rest>=T){
			auto it=S[j].upper_bound(i);
			if(it!=S[j].end()&&(p==SZ(all)||*it<=all[p]))S[j].erase(it),rest-=T,res.pb({cur,j}),cur+=T;
			else break;
		}
		rest=std::min(rest+1,T);
	}
	puts("Yes");printf("%d\n",SZ(all));
	for(auto it:all)printf("%d ",t[it]);
	printf("\n%d\n",SZ(res));
	for(const auto &it:res)printf("%d %d\n",it.first,it.second+1);
	return 0;
}