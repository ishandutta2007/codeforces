#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
using namespace std;
typedef long long ll;
const int N=1e5+10;
const int inf=1e6;
const int INF=1e9;
char str[N];int tot;
int nt[N],st[N],p[N],f[N],w[N],d[N],s[N],fr[N],v[N];
void init(int n){
	tot=0;rep(i,1,n)st[i]=-1;
}
void lk(int x,int y,int F,int W){
	nt[tot]=st[x];st[x]=tot;p[tot]=y;f[tot]=F;w[tot]=W;++tot;
	nt[tot]=st[y];st[y]=tot;p[tot]=x;f[tot]=0;w[tot]=-W;++tot;
}
int flow(int n){int ans=0;
	for(;;){
		rep(i,1,n)d[i]=i>1?-INF:0,s[i]=INF,fr[i]=-1,v[i]=0;
		queue<int>q;v[1]=1;q.push(1);
		while(!q.empty()){
			int x=q.front();v[x]=0;q.pop();
			for(int i=st[x];~i;i=nt[i])if(f[i]&&d[p[i]]<d[x]+w[i]){
				d[p[i]]=d[x]+w[i];
				s[p[i]]=min(s[x],f[i]);
				fr[p[i]]=i^1;
				if(!v[p[i]]){
					v[p[i]]=1;q.push(p[i]);
				}
			}
		}
		if(d[2]<=0)return ans;
		ans+=s[2]*d[2];
		for(int x=fr[2];~x;x=fr[p[x]])f[x]+=s[2],f[x^1]-=s[2];
	}
}
int main(){int n1,n2,m,r,b,cnt;
	scanf("%d%d%d%d%d",&n1,&n2,&m,&r,&b);init(n1+n2+2);cnt=n1+n2;
	scanf("%s",str+1);
	rep(i,1,n1)if(str[i]=='U')lk(1,i+2,inf,0),lk(i+2,2,inf,0),--cnt;
	else if(str[i]=='R')lk(1,i+2,1,inf),lk(1,i+2,inf,0);
	else if(str[i]=='B')lk(i+2,2,1,inf),lk(i+2,2,inf,0);
	scanf("%s",str+1);
	rep(i,1,n2)if(str[i]=='U')lk(1,i+n1+2,inf,0),lk(i+n1+2,2,inf,0),--cnt;
	else if(str[i]=='R')lk(i+n1+2,2,1,inf),lk(i+n1+2,2,inf,0);
	else if(str[i]=='B')lk(1,i+n1+2,1,inf),lk(1,i+n1+2,inf,0);
	rep(i,1,m){
		int x,y;scanf("%d%d",&x,&y);
		lk(x+2,y+n1+2,1,-r);lk(y+n1+2,x+2,1,-b);
	}
	int ans=cnt*inf-flow(n1+n2+2);
	if(ans>inf)return printf("-1\n"),0;
	printf("%d\n",ans);
	rep(i,1,m)if(f[tot-m*4+i*4-3])printf("R");
	else if(f[tot-m*4+i*4-1])printf("B");
	else printf("U");
}