#include<bits/stdc++.h>
using namespace std;
vector<int> pos[1505],g[1505];
int n,m,mch[1505],ans,vst[1505],used[1505],f[1505][1505],ch[10000005][2],len;
int tot,fail[10000005],ed[10000005],lst[10000005],t[10000005];
char str[10000005];
bool dfs(int x,int fr){
	vst[x]=fr;
	for(int y:g[x]){
		if(!mch[y])return mch[y]=x,1;
		else if(vst[mch[y]]!=fr&&dfs(mch[y],fr))return mch[y]=x,1;
	}
	return 0;
}
void dfs2(int x){
	if(used[x])return ;
	used[x]=1;
	if(x>n){for(int y:g[x])if(mch[x]^y)dfs2(y);}
	else dfs2(mch[x]);
}
int main(){
	//n=20;
	cin>>n;
	for(int i=1;i<=n;i++){
		//for(int j=0;j<500000-i;j++)str[j]='a';
		//for(int j=500000-i;j<=5000000;j++)str[j]=0;
		scanf("%s",str);
		len=strlen(str);
		int x=0;
		for(int j=0;j<len;j++){
			int w=str[j]-'a';
			if(!ch[x][w])ch[x][w]=++tot;
			x=ch[x][w],pos[i].push_back(x);
		}
		ed[x]=i;
		//cout<<i<<endl;
	}
	queue<int> q;
	for(int i=0;i<2;i++)if(ch[0][i])q.push(ch[0][i]);
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int i=0;i<2;i++){
			int y=ch[x][i];
			if(y)fail[y]=ch[fail[x]][i],q.push(y);
			else ch[x][i]=ch[fail[x]][i];
		}
	}
	//puts("PP");
	for(int i=1;i<=n;i++){
		for(int j:pos[i]){
			int p=j;
			if(ed[p]==i)p=fail[p];
			t[t[0]=1]=p;
			while(!ed[p]&&p&&!lst[p])p=fail[p],t[++t[0]]=p;
			if(lst[p]){
				for(int j=1;j<=t[0];j++)lst[t[j]]=lst[p];
				if(lst[p]!=-1)f[i][lst[p]]=1;
			}
			else if(ed[p]){
				f[i][ed[p]]=1;
				for(int j=1;j<=t[0];j++)lst[t[j]]=ed[p];
			}
			else {
				for(int j=1;j<=t[0];j++)lst[t[j]]=-1;
			}
		}
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)for(int k=1;k<=n;k++)if(f[j][i]&&f[i][k])f[j][k]=1;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(f[i][j])g[i].push_back(j+n),g[j+n].push_back(i);
	for(int i=1;i<=n;i++)if(dfs(i,i))ans++;
	cout<<n-ans<<endl;
	for(int i=n+1;i<=2*n;i++)if(mch[i])mch[mch[i]]=i;
	for(int i=n+1;i<=2*n;i++)if(!mch[i])dfs2(i);
	for(int i=1;i<=n;i++)if(used[i+n]&&!used[i])cout<<i<<' ';
}