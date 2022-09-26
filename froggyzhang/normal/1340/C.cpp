#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<deque>
using namespace std;
typedef long long ll;
#pragma GCC optimize(3)
const int inf=0x3f3f3f3f;
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
int n,m,g,r,d[10010],dis[10005][1010];
ll ans;
deque<pair<int,int> > q;
int main(){
	n=read(),m=read(),ans=1LL*inf*inf;
	for(int i=1;i<=m;++i){
		d[i]=read();
	}
	g=read(),r=read();
	sort(d+1,d+m+1);
	q.push_back(make_pair(1,0));
	memset(dis,0x3f,sizeof(dis));
	dis[1][0]=0;
	while(!q.empty()){
		int u=q.front().first,t=q.front().second;
		q.pop_front();
		if(t+n-d[u]<=g){
			ans=min(ans,1LL*dis[u][t]*(g+r)+t+n-d[u]);
		}
		if(u<m){
			int p=t+d[u+1]-d[u];
			if(p<=g){
				if(p==g&&dis[u+1][0]==inf){
					dis[u+1][0]=dis[u][t]+1;
					q.push_back(make_pair(u+1,0));
				}
				else if(dis[u+1][p]==inf){
					dis[u+1][p]=dis[u][t];
					q.push_front(make_pair(u+1,p));
				}
			}
		}
		if(u>1){
			int p=t+d[u]-d[u-1];
			if(p<=g){
				if(p==g&&dis[u-1][0]==inf){
					dis[u-1][0]=dis[u][t]+1;
					q.push_back(make_pair(u-1,0));
				}
				else if(dis[u-1][p]==inf){
					dis[u-1][p]=dis[u][t];
					q.push_front(make_pair(u-1,p));
				}
			}
		}
	}
	if(ans==1LL*inf*inf){
		printf("-1\n");
	}
	else{
		printf("%I64d\n",ans);
	}
	return 0;
}