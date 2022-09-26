#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
#define N 200020
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
int d1[N],n,m,dp1[N],dp2[N],cnt,head[N],dep[N],d2[N];
queue<int> q1,q2;
vector<int> G1[N],G2[N];
int main(){
	n=read(),m=read();
	for(int i=1;i<=m;++i){
		int u=read(),v=read();
		G1[u].push_back(v);
		G2[v].push_back(u); 
		++d1[v],++d2[u];
	}
	for(int i=1;i<=n;++i){
		dp1[i]=dp2[i]=i;
		if(!d1[i])q1.push(i);
		if(!d2[i])q2.push(i);
	}
	while(!q1.empty()){
		int u=q1.front();
		q1.pop();
		for(auto v:G1[u]){
			dp1[v]=min(dp1[v],dp1[u]);
			if(!--d1[v]){
				q1.push(v);
			}
		}
	}
	while(!q2.empty()){
		int u=q2.front();
		q2.pop();
		for(auto v:G2[u]){
			dp2[v]=min(dp2[v],dp2[u]);
			if(!--d2[v]){
				q2.push(v);
			}
		}
	}
	for(int i=1;i<=n;++i){
		if(d1[i]>0){
			printf("-1\n");
			return 0;
		}
	}
	int ans=0;
	for(int i=1;i<=n;++i){
		ans+=(dp1[i]==i&&dp2[i]==i);
	}
	printf("%d\n",ans);
	for(int i=1;i<=n;++i){
		putchar(dp1[i]==i&&dp2[i]==i?'A':'E');
	}
	return 0;
}