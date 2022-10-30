#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;
#define N 2000050
typedef long long ll;
char w[N>>1],a[N];
int ch[N][26],fa[N],len[N],cnt=1,lst=1,siz[N];
int ke[N],ro[N],nxt[N];
void insert(int x) {
	int p=lst,np=++cnt,q,nq; 
	lst=np; len[np]=len[p]+1;
	for(;p&&!ch[p][x];p=fa[p]) ch[p][x]=np;
	if(!p) fa[np]=1;
	else {
		q=ch[p][x];
		if(len[q]==len[p]+1) fa[np]=q;
		else {
			nq=++cnt;
			len[nq]=len[p]+1; fa[nq]=fa[q]; 
			memcpy(ch[nq],ch[q],sizeof(ch[q]));
			fa[np]=fa[q]=nq;
			for(;p&&ch[p][x]==q;p=fa[p]) ch[p][x]=nq;
		}
	}siz[lst]++;
}
int main() {
	int m,n;
	scanf("%s%d",w+1,&m);
	n=strlen(w+1);
	int i;
	for(i=1;i<=n;i++) insert(w[i]-'a');
	for(i=1;i<=cnt;i++) ke[len[i]]++;
	for(i=1;i<=cnt;i++) ke[i]+=ke[i-1];
	for(i=cnt;i;i--) ro[ke[len[i]]--]=i;
	for(i=cnt;i;i--) siz[fa[ro[i]]]+=siz[ro[i]];
	while(m--) {
		scanf("%s",a+1);
		int l=strlen(a+1),j;
		for(i=1;i<=l;i++) a[l+i]=a[i];
		nxt[1]=0;j=0;
		for(i=2;i<=l;i++) {
			for(;j&&a[j+1]!=a[i];j=nxt[j]);
			if(a[j+1]==a[i]) j++;
			nxt[i]=j;
		}
		for(j=nxt[l];l%(l-j);j=nxt[j]);
		int per=l-j;
		int lim=per+l-1,p=1,pl=0;
		ll ans=0;
		for(i=1;i<=lim;i++) {
			int x=a[i]-'a';
			if(ch[p][x]) {p=ch[p][x],pl++;}
			else {
				for(;p&&!ch[p][x];p=fa[p]) ;
				if(!p) {p=1; pl=0;}
				else {pl=len[p]+1;p=ch[p][x];}
			}
			while(fa[p]!=1&&len[fa[p]]>=l) p=fa[p],pl=len[p];
			if(pl>=l) {
				ans+=siz[p];
			}
		}
		printf("%lld\n",ans);
	}
}