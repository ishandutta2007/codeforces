#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
using namespace std;

#define forint(i, a, b) for(int i=(int)(a); i<=(int)(b); ++i)
#define forintdown(i, a, b) for(int i=(int)(a); i>=(int)(b); --i)
#define forn(i, n) forint(i, 0, (n)-1)
#define forndown(i, n) forintdown(i, (n)-1, 0)
#define fillchar(a, x) memset(a, x, sizeof(a))
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VPI;
#define MP make_pair
#define PB push_back
#define fi first
#define se second

const int MAXN=410;
const int MAXV=MAXN*MAXN;

int a[MAXN][MAXN];
int n, m;

struct Node {
	int i, j;
	Node *l, *r;
} nodes[MAXN][MAXN];
Node *last[MAXV];

int le[MAXN][MAXN], ri[MAXN][MAXN];

void cal(int up) {
	fillchar(last, 0);
	forint(j, 1, m) forint(i, up, n) {
		Node *cur=&nodes[i][j];
		int v=a[i][j];
		cur->i=i, cur->j=j;
		cur->l=last[v];
		cur->r=NULL;
		if(last[v]!=NULL) last[v]->r=cur;
		last[v]=cur;
	}
	forintdown(i, n, up) forintdown(j, m, 1) {
		Node *cur=&nodes[i][j];
		if(cur->l!=NULL) {
			le[i][j]=cur->l->j;
			cur->l->r=cur->r;
		} else
			le[i][j]=0;

		if(cur->r!=NULL) {
			ri[i][j]=cur->r->j;
			cur->r->l=cur->l;
		} else
			ri[i][j]=m+1;
	}
}

int la[MAXN];

int main() {
	cin>>n>>m;
	forint(i, 1, n) forint(j, 1, m) cin>>a[i][j];
	int ans=0;
	forint(up, 1, n) {
		cal(up);
		/*
		if(up==1) {
			forint(i, 1, n) { forint(j, 1, m) printf("(%d,%d) ", le[i][j],ri[i][j]);printf("\n");}
		}*/
		forint(j, 1, m) la[j]=0;
		forint(i, up, n) {
			forint(j, 1, m) {
				if(le[i][j]>=1) la[j]=max(la[j], le[i][j]);
				if(ri[i][j]<=m) la[ri[i][j]]=max(la[ri[i][j]], j);
			}
			int len=0;
			forint(j, 1, m) {
				++len;
				len=min(len, j-la[j]);
				int tmp=len*(i-up+1);
				ans=max(ans, tmp);
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}