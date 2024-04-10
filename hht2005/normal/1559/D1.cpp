#include<bits/stdc++.h>
using namespace std;
const int N=100010;
typedef pair<int,int> pii;
#define mp make_pair
set<pii>s[2];
vector<int>S[2][N];
int fa[2][N],siz[2][N],cnt,tim[N],p[N],tot,ans=0;
int A[N],B[N];
int get(int x,int f) {
	return fa[f][x]==x?x:fa[f][x]=get(fa[f][x],f);
}
void merge(int a,int b,int f) {
	S[f][a].push_back(b);
	S[f][b].push_back(a);
	int p=get(a,f),q=get(b,f);
	s[f].erase(mp(siz[f][p],p));
	s[f].erase(mp(siz[f][q],q));
	siz[f][q]+=siz[f][p];
	fa[f][p]=q;
	s[f].insert(mp(siz[f][q],q));
}
void dfs(int x) {
	tim[x]=cnt;
	p[++tot]=x;
	for(int y:S[0][x])
		if(tim[y]!=cnt)dfs(y);
}
int main() {
	int n,m1,m2,a,b;
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=n;i++) {
		fa[0][i]=fa[1][i]=i;
		siz[0][i]=siz[1][i]=1;
		s[0].insert(mp(1,i));
		s[1].insert(mp(1,i));
	}
	for(int i=1;i<=m1;i++) {
		scanf("%d%d",&a,&b);
		merge(a,b,0);
	}
	for(int i=1;i<=m2;i++) {
		scanf("%d%d",&a,&b);
		merge(a,b,1);
	}
	while(s[0].size()>1&&s[1].size()>1) {
		++cnt,tot=0;
		int x=s[0].begin()->second;
		dfs(x);
		int y=0,FL=0;
		for(int i=1;i<=n&&y==0;i++)
			if(tim[i]!=cnt)y=i;
		for(int i=1;i<=tot;i++)
			if(get(y,0)!=get(p[i],0)&&get(y,1)!=get(p[i],1)) {
				merge(y,p[i],0);
				merge(y,p[i],1);
				ans++;
				A[ans]=y;
				B[ans]=p[i];
				FL=1;
				break;
			}
		if(!FL) {
			int y=s[1].begin()->second;
			if(get(x,0)!=get(y,0)&&get(x,1)!=get(y,1)) {
				merge(x,y,0);
				merge(x,y,1);
				ans++;
				A[ans]=x;
				B[ans]=y;
			} else {
				y=(++s[1].begin())->second;
				merge(x,y,0);
				merge(x,y,1);
				ans++;
				A[ans]=x;
				B[ans]=y;
			}
		}
	}
	printf("%d\n",ans);
	for(int i=1;i<=ans;i++)
		printf("%d %d\n",A[i],B[i]);
	return 0;
}