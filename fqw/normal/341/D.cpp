#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef pair<int,int> PII;
#define fi first
#define se second
#define PB push_back
#define MP make_pair
template<class T> bool setmin(T &a, T b) {
	if(b<a) {a=b; return true;} else return false;
}
template<class T> bool setmax(T &a, T b) {
	if(b>a) {a=b; return true;} else return false;
}
#define forint(i, a, b) for(int i=(int)(a); i<=(int)(b); ++i)
#define forintdown(i, a, b) for(int i=(int)(a); i>=(int)(b); --i)
#define forn(i, n) for(int i=0; i<(int)(n); ++i)
#define forndown(i, n) for(int i=(int)(n)-1; i>=0; --i)
#define fillchar(a, x) memset(a, (x), sizeof(a))

const int MAXN=1010;

LL t[2][2][MAXN][MAXN];
int n;

LL get(int x, int y) {
	int a=x&1, b=y&1;
	x=(x+1)/2, y=(y+1)/2;
	LL ans=0;
	for(int i=x; i>=1; i-=(i&-i))
		for(int j=y; j>=1; j-=(j&-j))
			ans^=t[a][b][i][j];
	return ans;
}

void put(int x, int y, LL v) {
	int a=x&1, b=y&1;
	x=(x+1)/2, y=(y+1)/2;
	for(int i=x; i<=n; i+=(i&-i))
		for(int j=y; j<=n; j+=(j&-j))
			t[a][b][i][j]^=v;
}

int main() {
	int qs;
	scanf("%d%d", &n,&qs);
	++n;
	fillchar(t, 0);
	while(qs--) {
		int op;
		int x1, y1, x2, y2;
		LL v;
		scanf("%d", &op);
		scanf("%d%d%d%d", &x1,&y1,&x2,&y2);
		if(op==1) {
			LL ans=get(x2, y2);
			ans^=get(x1-1, y2);
			ans^=get(x2, y1-1);
			ans^=get(x1-1, y1-1);
			cout<<ans<<endl;
		} else {
			cin>>v;
			put(x1, y1, v);
			put(x2+1, y1, v);
			put(x1, y2+1, v);
			put(x2+1, y2+1, v);
		}
	}
	return 0;
}