#include<bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=a,i##_end=b;i<i##_end;++i)
using ll=long long;
using pii=pair<int,int>;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
const int oo=~0u>>2;
mt19937 rnd(time(0));

const int N=6011,M=N*211;
int n,a[N],b[N];
int S,T,cnt=1,hd[N],to[M],cap[M],nxt[M];
void ade(int x,int y,int f){
	//cerr<<x<<" "<<y<<" "<<f<<endl;
	to[++cnt]=y,cap[cnt]=f,nxt[cnt]=hd[x],hd[x]=cnt;
	to[++cnt]=x,cap[cnt]=0,nxt[cnt]=hd[y],hd[y]=cnt;
}
int q[N],d[N];
int bfs(){
	memset(d,-1,sizeof d);
	d[S]=1;
	int h=0,t=0;
	q[t++]=S;
	while(h<t){
		int x=q[h++];
		for(int i=hd[x];i;i=nxt[i])if(cap[i]){
			int y=to[i];
			if(~d[y])continue;
			d[y]=d[x]+1;
			q[t++]=y;
		}
	}
	return ~d[T];
}
int dfs(int x,int mf){
	//cerr<<x<<" "<<mf<<" "<<d[x]<<" "<<d[T]<<endl;
	if(x==T||!mf)return mf;
	int lf=mf;
	for(int i=hd[x];i;i=nxt[i])if(cap[i]){
		int y=to[i];
		if(d[y]!=d[x]+1)continue;
		int f=dfs(y,min(lf,cap[i]));
		cap[i]-=f,cap[i^1]+=f;
		lf-=f;
		if(!f)d[y]=-1;
	}
	return mf-lf;
}
int now[111];
int main(){
#ifdef SGR
	freopen("a.txt","r",stdin);
#endif
	ios::sync_with_stdio(0);
	cin>>n;
	For(i,1,n+1)cin>>a[i];
	For(i,1,n+1)cin>>b[i];
	int ans=0;
	For(i,1,n+1)if(b[i]>0)ans+=b[i];
	S=0,T=n+1;
	For(i,1,n+1)
		if(b[i]==0)continue;
		else if(b[i]>0){
			ade(S,i,b[i]);
			For(j,1,a[i]+1)if(a[i]%j==0&&now[j])
				ade(i,now[j],oo);
		}else{
			ade(i,T,-b[i]);
			if(now[a[i]])
				ade(i,now[a[i]],oo);
			now[a[i]]=i;
		}
	while(bfs())ans-=dfs(S,oo);
	cout<<ans<<endl;
}