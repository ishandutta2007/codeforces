#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <vector>
using namespace std;
#define N 1000050
int n,cnt,fail[N],ch[N][26],len[N],diff[N],top[N],lst;
int f[N],frm[N],g[N],pos[N];
char s[N],t[N],a[N];
vector<pair<int,int> >ans;
void insert(int x) {
	int c=a[x]-'a',p=lst;
	for(;a[x]!=a[x-len[p]-1];p=fail[p]);
	if(!ch[p][c]) {
		int np=++cnt,q=fail[p];
		len[np]=len[p]+2;
		for(;a[x]!=a[x-len[q]-1];q=fail[q]);
		fail[np]=ch[q][c];
		ch[p][c]=np;
		diff[np]=len[np]-len[fail[np]];
		top[np]=diff[np]==diff[fail[np]]?top[fail[np]]:fail[np];
	}
	lst=ch[p][c];
}
bool check(int l,int r) {
	int i;
	for(i=l;i<=r;i+=2) if(a[i]!=a[i+1]) return 1;
	return 0;
}
int main() {
	scanf("%s%s",s+1,t+1);
	int l=strlen(s+1),i;
	for(i=1;i<=l;i++) a[++n]=s[i],a[++n]=t[i];
	fail[0]=fail[1]=1; len[1]=-1; cnt=1; diff[0]=1; lst=0;
	g[0]=1<<30;
	for(i=1;i<=n;i++) {
		insert(i); f[i]=1<<30;
		if(a[i]==a[i-1]) f[i]=f[i-2],frm[i]=i-2;
		int p=lst;
		for(;p;p=top[p]) {
			g[p]=f[i-len[top[p]]-diff[p]];
			pos[p]=i-len[top[p]]-diff[p];
			if(diff[p]==diff[fail[p]]&&g[fail[p]]<g[p]) {
				g[p]=g[fail[p]];
				pos[p]=pos[fail[p]];
			}
			if(g[p]+1<f[i]) {
				f[i]=g[p]+1; frm[i]=pos[p];
			}
		}
		if(i&1) f[i]=1<<30;
	}
	if(f[n]==1<<30) {puts("-1");return 0;}
	while(n) {
		if(check(frm[n]+1,n))ans.push_back(pair<int,int>(frm[n]/2+1,n/2));
		n=frm[n];	
	}
	int lim=ans.size();
	printf("%d\n",lim);
	for(i=0;i<lim;i++) printf("%d %d\n",ans[i].first,ans[i].second);

	return 0;
}