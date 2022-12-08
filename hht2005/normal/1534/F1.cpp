#include<bits/stdc++.h>
using namespace std;
const int maxn=400010;
string s[maxn];
vector<int>id[maxn];
int hea[maxn],nxt[maxn*4],to[maxn*4],tot,low[maxn],dfn[maxn],sk[maxn],in[maxn],rd[maxn],dfns,top,Cnt;
void add(int a,int b) {
	if(a==0)return;
	nxt[++tot]=hea[a];
	hea[a]=tot;
	to[tot]=b;
}
void tarjan(int x) {
    low[x]=dfn[x]=++dfns;
    sk[++top]=x;
    for(int i=hea[x];i;i=nxt[i]) {
        if(!dfn[to[i]]) {
            tarjan(to[i]);
            low[x]=min(low[x],low[to[i]]);
        }
        else if(!in[to[i]])low[x]=min(low[x],dfn[to[i]]);
    }
    if(low[x]==dfn[x]) {
        Cnt++;
        while(sk[top]!=x)in[sk[top--]]=Cnt;
        in[sk[top--]]=Cnt;
    }
}
int main() {
	int n,m,cnt=0,ans=0;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++) {
		cin>>s[i];
		id[i]=vector<int>(m);
		for(int j=0;j<m;j++)
			if(s[i][j]=='#')id[i][j]=++cnt;
	}
	for(int i=0;i<m;i++) {
		int las=0;
		for(int j=0;j<n;j++) {
			if(s[j][i]=='#') {
				if(j>0&&s[j-1][i]=='#')add(id[j][i],las);
				add(las,id[j][i]),las=id[j][i];
			} if(i>0&&s[j][i-1]=='#')add(las,id[j][i-1]);
			if(i<m-1&&s[j][i+1]=='#')add(las,id[j][i+1]);
		}
	}
	for(int i=1;i<=cnt;i++)
		if(!dfn[i])tarjan(i);
	for(int i=1;i<=cnt;i++)
		for(int j=hea[i];j;j=nxt[j])
			if(in[i]!=in[to[j]])
				rd[in[to[j]]]++;
	for(int i=1;i<=Cnt;i++)
		if(!rd[i])ans++;
	printf("%d\n",ans);
	return 0;
}