#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int id[60][1030],n,a[12][205],pos[12][205][2],num[12][205],nxt[12][205][205],tot=0,ch[100005],is[100005];
int f[100005],vst[100005];
char str[205];
vector<int> g[100005];
int Id(int x){
	if(x>='a'&&x<='z')return x-'a'+1;
	if(x>='A'&&x<='Z')return x-'A'+27;
	assert(0);
	return 0;
}
char Rev(int x){
	if(x<=26)return 'a'+x-1;
	else return 'A'+x-27;
}
void dfs(int x){
	if(vst[x])return ;
	f[x]=1,vst[x]=1;
	for(int y:g[x])dfs(y),f[x]=max(f[x],f[y]+1);
}
void Print(int x){
	cout<<Rev(ch[x]);
	for(int y:g[x]){
		if(f[y]+1==f[x]){
			Print(y);
			return ;
		}
	}
}
void Solve(){
	for(int i=1;i<=tot;i++)ch[i]=is[i]=f[i]=vst[i]=0,g[i].clear();
	memset(id,0,sizeof(id)),tot=0,memset(a,0,sizeof(a));
	memset(nxt,0,sizeof(nxt)),memset(pos,0,sizeof(pos)),memset(num,0,sizeof(num));
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s",str+1);
		int len=strlen(str+1);
		for(int j=1;j<=len;j++){
			a[i][j]=Id(str[j]);
			if(pos[i][a[i][j]][0])pos[i][a[i][j]][1]=j,num[i][j]=1;
			else pos[i][a[i][j]][0]=j,num[i][j]=0;
		}
		for(int j=len;j>=1;j--){
			for(int k=1;k<=52;k++)nxt[i][j][k]=nxt[i][j+1][k];
			nxt[i][j][a[i][j]]=j;
		}
	}
	for(int i=1;i<=52;i++)for(int j=0;j<(1<<n);j++)id[i][j]=++tot,ch[tot]=i;
	for(int i=1;i<=52;i++){
		for(int j=0;j<(1<<n);j++){
			bool flag=0;
			for(int k=0;k<n;k++){
				int w=(j>>k)&1;
				if(!pos[k][i][w])flag=1;
			}
			if(flag)continue;
			is[id[i][j]]=1;
			for(int c=1;c<=52;c++){
				bool ff=0;
				int to=0;
				for(int k=0;k<n;k++){
					int w=(j>>k)&1;
					if(!nxt[k][pos[k][i][w]+1][c])ff=1;
					else if(num[k][nxt[k][pos[k][i][w]+1][c]])to|=(1<<k);
				}
				if(ff)continue;
				g[id[i][j]].push_back(id[c][to]);
			}
		}
	}
	int ans=0,S=0;
	for(int i=1;i<=tot;i++){
		if(!is[i])continue;
		dfs(i);
		if(f[i]>ans)ans=f[i],S=i;
	}
	if(ans){
		cout<<ans<<'\n';
		Print(S),cout<<'\n';
	}
	else {
		puts("0\n");
	}
}
int main(){
	int t;
	cin>>t;
	while(t--)Solve();
}