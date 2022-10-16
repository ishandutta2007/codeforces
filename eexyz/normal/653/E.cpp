#include<bits/stdc++.h>
using namespace std;
#define N 1000005
#define M 1000005
inline int read(){int x;cin>>x;return x;}
int x[M],i,gg[N],qwq,cc[N],mn,cl,ps,k,GG,rev[N],y[M],e[N],j,col[N],ans,n,m,cnt,d[N],vis[N],t[1000][1000];
void dfs(int now){
	col[e[now]]=cl;
	for(int i=1;i<=cnt;++i)if(!col[e[i]]&&t[now][i])dfs(i);
}
int main(){
	n=read();m=read();k=read();
	for(i=1;i<=m;++i){
		x[i]=read(),y[i]=read();
		if(x[i]==1||y[i]==1)gg[x[i]+y[i]-1]=1,--i,--m,++qwq;
		else ++d[x[i]],++d[y[i]];
	}
	if(n-1-qwq<k)return cout<<"impossible",0;
	for(mn=m+1,i=2;i<=n;++i)if(d[i]<mn)mn=d[i],ps=i;
	for(i=1;i<=m;++i){
		if(x[i]==ps)vis[y[i]]=1;
		if(y[i]==ps){
			vis[x[i]]=1;
		}
	}
	for(i=2;i<=n;++i)if(!vis[i]&&i!=ps)col[i]=1;
	GG=n-mn-1;
	for(i=2;i<=n;++i)
		if(vis[i])rev[i]=++cnt,e[cnt]=i;
	++cnt;rev[ps]=cnt,e[cnt]=ps;
	for(i=1;i<=m;++i){
		if(vis[x[i]]&&vis[y[i]])t[rev[x[i]]][rev[y[i]]]=1;
		else if(vis[x[i]])++t[rev[x[i]]][cnt];
		else if(vis[y[i]])++t[rev[y[i]]][cnt];
	}
	for(i=1;i<=cnt;++i)for(j=1;j<i;++j)t[i][j]=t[i][j]+t[j][i];
	for(i=1;i<=cnt;++i)for(j=1;j<i;++j){
		if(i==cnt){
			if(t[i][j]^GG)t[i][j]=t[j][i]=1;
			else t[j][i]=t[i][j]=0;
		}
		else t[i][j]^=1,t[j][i]=t[i][j];
	}
	cl=1;dfs(cnt);
	for(i=1;i<cnt;++i){
		if(!col[e[i]]){
			++cl;dfs(i);
		}
	}
//	for(i=1;i<=n;++i)cout<<col[i]<<" ";cout<<"\n";
	for(i=2;i<=n;++i){
		if(!gg[i]&&!cc[col[i]]){
			cc[col[i]]=1;--k;
		}
	}
	if(k<0)return cout<<"impossible",0;
	for(i=1;i<=cl;++i)if(!cc[i])return cout<<"impossible",0;
	cout<<"possible";
}