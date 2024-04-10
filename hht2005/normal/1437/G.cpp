#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10,mod=998244353;
int tr[maxn][26],nxt[maxn],pos[maxn],en[maxn],now[maxn],w[maxn],q[maxn],tot,h,e;
char s[maxn];
multiset<int>val[maxn];
int main() {
	int n,m,opt,x,v;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) {
		scanf("%s",s+1);
		int len=strlen(s+1),p=0;
		for(int j=1;j<=len;j++) {
			if(!tr[p][s[j]-'a'])tr[p][s[j]-'a']=++tot;
			p=tr[p][s[j]-'a'];
		}
		pos[i]=p;
		en[p]=i;
		val[p].insert(0);
	}
	h=1,e=0;
	for(int i=0;i<26;i++)
		if(tr[0][i])q[++e]=tr[0][i];
	while(h<=e) {
		int p=q[h++];
		for(int i=0;i<26;i++)
			if(tr[p][i])nxt[q[++e]=tr[p][i]]=tr[nxt[p]][i];
			else tr[p][i]=tr[nxt[p]][i];
	}
	for(int I=1;I<=m;I++) {
		scanf("%d",&opt);
		if(opt==1) {
			scanf("%d%d",&x,&v);
			val[pos[x]].erase(val[pos[x]].find(w[x]));
			val[pos[x]].insert(v);
			w[x]=v;
		} else {
			scanf("%s",s+1);
			int ans=-1;
			int len=strlen(s+1),p=0;
			for(int i=1;i<=len;i++) {
				p=tr[p][s[i]-'a'];
				for(int j=p;j&&now[j]<I;j=nxt[j]) {
					if(en[j])ans=max(ans,*val[j].rbegin());
					now[j]=I;
				}
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}