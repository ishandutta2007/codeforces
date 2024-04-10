#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 505
char w[N];
int fa[N][N],ans,val[N],n,K,cnt=1,ch[N][12];
int len[N],tmp[N][12],siz[N];
int f[N][N][12],dep[N],wa[N];
inline void upd(int &x,int y) {
	x=x>y?x:y;
}
void dfs(int x) {
	int i,j,k,l;
	fa[x][0]=x;
	siz[x]=1;
	for(i=0;i<=len[x];i++) {
		f[x][i][!i]=dep[fa[x][i]]*wa[x];
	}
	for(i=0;i<10;i++) if(ch[x][i]) {
		int t=ch[x][i];
		dep[t]=dep[x]+1;
		for(j=0;j<=len[x];j++) fa[t][++len[t]]=fa[x][j];

		dfs(t);
		for(j=0;j<=len[x];j++) {
			for(k=0;k<=siz[x]&&k<=K;k++) {
				tmp[j][k]=f[x][j][k];
				f[x][j][k]=-0x3f3f3f3f;
			}
		}
		for(j=0;j<=len[x];j++) {
			for(k=0;k<=siz[x]&&k<=K;k++) {
				for(l=0;l<=siz[t]&&k+l<=K;l++) {
					upd(f[x][j][k+l],tmp[j][k]+max(f[t][j+1][l],f[t][0][l]));
				}
			}
		}
		siz[x]+=siz[t];
	}
}
int main() {
	memset(f,0xc0,sizeof(f));
	scanf("%d%d",&n,&K); K++;
	int i,j;
	for(i=1;i<=n;i++) {
		scanf("%s%d",w+1,&val[i]);
		int l=strlen(w+1);
		ans+=l*val[i];
		int p=1;
		for(j=1;j<=l;j++) {
			int &k=ch[p][w[j]-'0'];
			if(!k) k=++cnt;
			p=k; 
		}
		wa[p]+=val[i];
	}
	dfs(1);
	int mx=0;
	for(i=1;i<=K;i++) mx=max(mx,f[1][0][i]);
	printf("%d\n",ans-mx);
}