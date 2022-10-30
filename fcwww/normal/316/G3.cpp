#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 1000050
int ch[N][26],len[N],fa[N],cnt=1,lst=1;
int ke[N],ro[N],ql[N],qr[N];
char s[N],w[N];
int n,NOT[N],siz[N][11];
void insert(int x,int op) {
	

	int p=lst,np=cnt,q,nq;
	if(ch[p][x]) {
		q=ch[p][x];
		if(len[q]==len[p]+1) lst=q;
		else {
			nq=++cnt; len[nq]=len[p]+1; lst=nq;
			memcpy(ch[nq],ch[q],sizeof(ch[q]));
			fa[nq]=fa[q]; fa[q]=nq;
			for(;p&&ch[p][x]==q;p=fa[p]) ch[p][x]=nq;
		}
		siz[lst][op]++;
		return ;
	}
	np=++cnt;
	lst=np, len[np]=len[p]+1;
	for(;p&&!ch[p][x];p=fa[p]) ch[p][x]=np;
	if(!p) fa[np]=1;
	else {
		q=ch[p][x];
		if(len[q]==len[p]+1) fa[np]=q;
		else {
			nq=++cnt; len[nq]=len[p]+1;
			memcpy(ch[nq],ch[q],sizeof(ch[q]));
			fa[nq]=fa[q];
			fa[q]=fa[np]=nq;
			for(;p&&ch[p][x]==q;p=fa[p]) ch[p][x]=nq;
		}
	}
	siz[lst][op]++;
}
int main() {
	scanf("%s%d",s+1,&n);
	int i,m=strlen(s+1),j;
	for(i=1;i<=m;i++) insert(s[i]-'a',0);
	for(i=1;i<=n;i++) {
		scanf("%s%d%d",w+1,&ql[i],&qr[i]);
		int k=strlen(w+1);
		lst=1;
		for(j=1;j<=k;j++) {
			insert(w[j]-'a',i);
		}
	}	
	for(i=1;i<=cnt;i++) ke[len[i]]++;
	for(i=1;i<=cnt;i++) ke[i]+=ke[i-1];
	for(i=cnt;i;i--) ro[ke[len[i]]--]=i;
	for(i=cnt;i;i--) {
		int p=ro[i];
		for(j=0;j<=n;j++) siz[fa[p]][j]+=siz[p][j];
	}
	long long ans=0;
	for(i=2;i<=cnt;i++) if(siz[i][0]) {
		int flg=1;
		for(j=1;j<=n;j++) if(siz[i][j]<ql[j]||siz[i][j]>qr[j]) {flg=0; break;}
		if(flg) ans+=len[i]-len[fa[i]];
	}
	printf("%lld\n",ans);
}