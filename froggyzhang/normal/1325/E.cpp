#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<cstdlib>
using namespace std;
const int inf=0x3f3f3f3f;
#define N 2000100
inline int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*f;
}
int p[N],pn,pos[N],ans,R,n,dis[N];
bool ntp[N];
void init(int n){
	ntp[1]=true;
	pos[1]=R=1;
	for(register int i=2;i<=n;i++){
		if(!ntp[i]){
			p[++pn]=i,pos[i]=pn+1;
			if(i<1000)++R;
		}
		for(int j=1;j<=pn&&p[j]*i<=n;++j){
			ntp[p[j]*i]=true;
			if(i%p[j]==0)break;
		}
	}
}
int cnt,head[N];
struct Edge{
	int to,nxt;
}edge[N<<1];
void add(int a,int b){
	++cnt;
	edge[cnt].to=b;
	edge[cnt].nxt=head[a];
	head[a]=cnt;
}
void check(int x){
	int p=0,q=0;
	for(register int i=2;i*i<=x;i++){
		if(x%i==0){
			int cnt=0;
			while(x%i==0)++cnt,x/=i;
			if(cnt&1){
				if(!p)p=i;
				else q=i;
			}
		}
	}
	if(x>1){
		if(!p)p=x;
		else q=x;
	}
	if(!p&&!q){
		printf("1\n");
		exit(0);
	}
	if(!q){
		add(pos[p],1),add(1,pos[p]);	
	}
	else{
		add(pos[q],pos[p]),add(pos[p],pos[q]);
	}
}
int main(){
	n=read();
	init(1000000);
	ans=inf;
	for(int i=1;i<=n;i++){
		int x=read();
		check(x);
	}
	for(int s=1;s<=R;++s){
		memset(dis,0x3f,sizeof(dis));
		dis[s]=0;
		queue<pair<int,int> > q;
		q.push(make_pair(s,0));
		while(!q.empty()){
			int u=q.front().first,fa=q.front().second;
			q.pop();
			for(int i=head[u];i;i=edge[i].nxt){
				int v=edge[i].to;
				if(v==fa)continue;
				if(dis[v]>=inf){
					dis[v]=dis[u]+1;
					q.push(make_pair(v,u));
				}
				else if(dis[u]+dis[v]>0){
					ans=min(ans,dis[u]+dis[v]+1);
				}
			}
		}
	}
	if(ans>n){
		printf("-1\n");
	}
	else{
		printf("%d\n",ans);
	}
	return 0;
}