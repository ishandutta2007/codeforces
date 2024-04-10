#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
#define N 1000100
int n,dfn[N],num,dp[N],cnt[N],mk[N],m,a[N];
char s[3],ch[N];
vector<int> edge[N];
multiset<int> S;
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
bool cmp(int i,int j){
	return ch[i]<ch[j];
}
void dfs1(int u){
	dfn[u]=++num;
	cnt[num]=mk[u];
	for(int i=0;i<edge[u].size();i++){
		int v=edge[u][i];
		dfs1(v);
	}
}
void dfs(int u,int fa=-1){
	if(fa!=-1){
		dp[u]=dp[fa]+1;
	}
	else {
		dp[u]=0;
	}
	if(mk[u])dp[u]=min(dp[u],*S.begin()+cnt[dfn[u]]);
	int tp=dp[u]-cnt[dfn[u]-1];
	S.insert(tp);
	for(int i=0;i<edge[u].size();i++){
		int v=edge[u][i];
		dfs(v,u);
	}
	S.erase(S.find(tp));
}
int main(){
	n=read();
	for(int i=1;i<=n;i++){
		int fa=read();
		scanf("%s",s+1);
		edge[fa].push_back(i);
		ch[i]=s[1];
	}
	for(int i=0;i<=n;i++){
		sort(edge[i].begin(),edge[i].end(),cmp);
	}
	m=read();
	for(int i=1;i<=m;i++){
		a[i]=read();
		mk[a[i]]=1;
	}
	dfs1(0);
	for(int i=1;i<=n+1;i++){
		cnt[i]+=cnt[i-1];
	}
	dfs(0);
	for(int i=1;i<=m;i++){
		printf("%d ",dp[a[i]]);
	}
	return 0;
}