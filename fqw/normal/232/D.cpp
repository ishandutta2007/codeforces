#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int,int> PII;
#define PB push_back
#define MP make_pair

const int MAXN=100010;
const int MAXLen=MAXN*2;
const int MAXLogL=20;
const int MAXNodes=MAXLen*4;

int sa[MAXLen], rank[MAXLen], height[MAXLen];
int wxa[MAXLen], wxb[MAXLen], wxc[MAXLen];
int str[MAXLen];
int len;
void cal_sa() {
	vector<int> hash;
	for(int i=1; i<=len; ++i)
		hash.PB(str[i]);
	sort(hash.begin(), hash.end());
	hash.erase(unique(hash.begin(), hash.end()), hash.end());
	for(int i=1; i<=len; ++i)
		str[i]=(int)(lower_bound(hash.begin(), hash.end(), str[i]) - hash.begin()+1);
	int *x=wxa, *y=wxb, *c=wxc, size=len;
	for(int i=0; i<=size; ++i) c[i]=0;
	for(int i=1; i<=len; ++i) ++c[x[i]=str[i]];
	for(int i=1; i<=size; ++i) c[i]+=c[i-1];
	for(int i=len; i>=1; --i) sa[c[x[i]]--]=i;
	for(int w=1; w<len; w*=2, size=len) {
		int p=0;
		for(int i=len-w+1; i<=len; ++i) y[++p]=i;
		for(int i=1; i<=len; ++i) if(sa[i]>w) y[++p]=sa[i]-w;
		for(int i=0; i<=size; ++i) c[i]=0;
		for(int i=1; i<=len; ++i) ++c[x[i]];
		for(int i=1; i<=size; ++i) c[i]+=c[i-1];
		for(int i=len; i>=1; --i) sa[c[x[y[i]]]--]=y[i];
		std::swap(x,y); x[sa[1]]=1;
		for(int i=2; i<=len; ++i) {
			int j1=sa[i-1], j2=sa[i];
			int c1=y[j1], c2=y[j2];
			if(c1==c2) {
				c1=(j1+w<=len?y[j1+w]:0);
				c2=(j2+w<=len?y[j2+w]:0);
			}
			x[j2]=x[j1]+(c1<c2);
		}
	}
}
void cal_height() {
	for(int i=1; i<=len; ++i) rank[sa[i]]=i;
	for(int i=1, h=0; i<=len; ++i) {
		if(h>0) --h;
		int j=sa[rank[i]-1];
		while(i+h<=len && j+h<=len && str[i+h]==str[j+h])
			++h;
		height[rank[i]]=h;
	}
}
int lcp_st[MAXLogL][MAXLen];
void cal_lcp() {
	for(int i=2; i<=len; ++i) lcp_st[0][i]=height[i];
	for(int k=1, w=1; 2+w<=len; ++k, w*=2)
		for(int i=2; i+w<=len; ++i)
			lcp_st[k][i]=min(lcp_st[k-1][i], lcp_st[k-1][i+w]);
}

vector<int> tr[MAXNodes];
void ins(int x, int s, int t, int ind, int val) {
	tr[x].PB(val);
	if(s==t) return;
	int mid=(s+t)/2;
	if(ind<=mid) ins(x*2, s, mid, ind, val);
		else ins(x*2+1, mid+1, t, ind, val);
}
int query(int x, int s, int t, int st, int en, int l, int r) {
	if(st<=s && t<=en) {
		/*
		int ans=0;
		for(int i=0; i<(int)tr[x].size(); ++i)
			if(tr[x][i]<=r && tr[x][i]>=l) ++ans;
		return ans;
		*/
		//*
		vector<int>::iterator ir=lower_bound(tr[x].begin(), tr[x].end(), r+1);
		//if(ir==tr[x].end()) return 0;
		vector<int>::iterator il=lower_bound(tr[x].begin(), tr[x].end(), l);
		if(il==tr[x].end()) return 0;
		return max(0, (int)(ir-il));
		//*/
	}
	int mid=(s+t)/2;
	int ans=0;
	if(st<=mid) ans+=query(x*2, s, mid, st, en, l, r);
	if(mid<en) ans+=query(x*2+1, mid+1, t, st, en, l, r);
	return ans;
}

int A[MAXN], B[MAXN];
int Pos[MAXN];
int N;

int main() {
	scanf("%d", &N);
	for(int i=1; i<=N; ++i) scanf("%d", &A[i]);
	for(int i=1; i<N; ++i) B[i]=A[i+1]-A[i];
	len=0;
	for(int i=1; i<=N-1; ++i)
		str[++len]=B[i];
	str[++len]=2147483647;
	for(int i=1; i<=N-1; ++i) {
		str[++len]=-B[i];
		Pos[i]=len;
	}
	//printf("len=%d\n", len);
	//for(int i=1; i<=len; ++i) printf("%d ",str[i]); printf("\n");
	cal_sa();
	cal_height();
	cal_lcp();
	//for(int i=1; i<=len; ++i) printf("%d ",str[i]); printf("\n");

	for(int i=0; i<MAXNodes; ++i) tr[i].clear();
	for(int i=1; i<=N-1; ++i)
		ins(1, 1, len, rank[i], i);
	for(int i=0; i<MAXNodes; ++i)
		if(tr[i].size()>0)
			sort(tr[i].begin(), tr[i].end());
	
	int M; scanf("%d", &M);
	while(M--) {
		int l, r; scanf("%d%d", &l, &r);
		int d=r-l+1;
		if(d==1) {
			printf("%d\n", N-1);
			continue;
		}
		int s1=1, t1=l-d;
		int s2=r+1, t2=N-d+1;
		int p=rank[Pos[l]];
		int p1=p, p2=p;
		for(int i=MAXLogL-1; i>=0; --i)
			if(p1-(1<<i)>=1 && lcp_st[i][p1-(1<<i)+1]>=d-1)
				p1-=(1<<i);
		for(int i=MAXLogL-1; i>=0; --i)
			if(p2+(1<<i)<=len && lcp_st[i][p2+1]>=d-1)
				p2+=(1<<i);
		int ans1=query(1, 1, len, p1, p2, s1, t1);
		int ans2=query(1, 1, len, p1, p2, s2, t2);
		int ans=ans1+ans2;
		printf("%d\n", ans);
	}

	return 0;
}