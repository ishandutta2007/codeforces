#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
struct side{
	int a,b,c,id;
	int operator<(const side &a)const {
		return c<a.c;
	}
}S[N];
int fa[N],A[2*N],pos[N],p[N],q[N];
int get(int x) {
	return x==fa[x]?x:fa[x]=get(fa[x]);
}
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++) {
		scanf("%d%d%d",&S[i].a,&S[i].b,&S[i].c);
		S[i].id=i;
	}
	sort(S+1,S+m+1);
	for(int i=1;i<=m;i++)
		pos[S[i].id]=i;
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for(int l=1;l<=m;l++) {
		int r=l;
		while(r<m&&S[r].c==S[r+1].c)r++;
		for(int i=l;i<=r;i++)
			p[i]=get(S[i].a),q[i]=get(S[i].b);
		for(int i=l;i<=r;i++) {
			int p=get(S[i].a),q=get(S[i].b);
			if(p==q)continue;
			fa[p]=q;
		}
		l=r;
	}
	for(int i=1;i<=n;i++)
		fa[i]=i;
	int QAQ,k;
	scanf("%d",&QAQ);
	while(QAQ--) {
		scanf("%d",&k);
		int cnt=0,a,FL=1;
		for(int i=1;i<=k;i++) {
			scanf("%d",&a);
			int P=get(p[pos[a]]),Q=get(q[pos[a]]);
			if(P==Q)FL=0;
			A[++cnt]=P,A[++cnt]=Q;
			fa[P]=Q;
		}
		puts(FL?"YES":"NO");
		for(int i=1;i<=cnt;i++)
			fa[A[i]]=A[i];
	}
	return 0;
}