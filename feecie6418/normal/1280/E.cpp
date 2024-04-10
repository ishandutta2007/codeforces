#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int m,st[1000005],top,R,tp[1000005],f[1000005];//0: 1: 
ll ans[1000005];
char str[1000005],a[1000005];
vector<int> g[1000005];
void dfs(int x){
	if(tp[x]==2)return f[x]=1,void();
	if(tp[x]==1)f[x]=1e9;
	else f[x]=0;
	for(int y:g[x]){
		dfs(y);
		if(tp[x]==1)f[x]=min(f[x],f[y]);
		else f[x]+=f[y];
	}
}
void printval(int x,ll v){
	if(tp[x]==2)return ans[x]=v*f[0],void();
	if(tp[x]==0){
		for(int y:g[x])printval(y,v);
		return ;
	}
	for(int y:g[x]){
		if(f[y]==f[x]){
			printval(y,v);
			f[x]=1e9+1;
		}
		else printval(y,0);
	}
}
void Solve(){
	scanf("%d",&R),m=0;
	int tmp=0;
	while(1){
		scanf("%s",str);
		int len=strlen(str);
		for(int i=0;i<len;i++){
			a[++m]=str[i];
			if(str[i]=='(')tmp++;
			if(str[i]==')')tmp--;
		}
		if(!tmp)break;
	}
	top=0;
	for(int i=1;i<=m;i++){
		if(a[i]=='P')tp[st[top]]=0;
		if(a[i]=='S')tp[st[top]]=1;
		if(a[i]=='(')g[st[top]].push_back(i),st[++top]=i;
		if(a[i]=='*')g[st[top]].push_back(i),tp[i]=2;
		if(a[i]==')')top--;
	}
	assert(top==0);
	dfs(0),printf("REVOLTING "),printval(0,1);
	for(int i=1;i<=m;i++)if(a[i]=='*')printf("%lld ",ans[i]*R);
	puts("");
	for(int i=0;i<=m;i++)g[i].clear();
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--)Solve();
}