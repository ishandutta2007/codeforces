#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
#include <map>
using namespace std;

#define _ (size_t)
#define all(a) a.begin(), a.end()
#define forint(i, a, b) for(int i=int(a); i<=int(b); ++i)
#define forintdown(i, a, b) for(int i=int(a); i>=int(b); --i)
#define forn(i, n) forint(i, 0, (n)-1)
#define forndown(i, n) forintdown(i, (n)-1, 0)
#define fillchar(a, x) memset(a, x, sizeof(a))
#define fi first
#define se second
#define PB push_back
#define MP make_pair
typedef long long LL;
typedef pair<double,double> PDD;
typedef pair<int,int> PII;
typedef vector<string> VS;
typedef vector<int> VI;
typedef vector<PII> VPI;
template<class T> void setmax(T &a, T b) { if(b>a) a=b; }
template<class T> void setmin(T &a, T b) { if(b<a) a=b; }
template<class T> T gcd(T a, T b) { return b==0?a:gcd(b,a%b); }


// ------------------------ template ends here ------------------------ //
map<PII, int> box_id;
PII boxes[100000];

int get_box_id(PII b) {
	if(box_id.find(b)==box_id.end())
		return -1;
	return box_id[b];
}

set<int> valid_boxes;
bool valid[100000];

bool is_dangerous(PII b) {
	if(get_box_id(b)<0)
		return false;
	int cnt=0;
	forint(j, -1, 1)
		if(get_box_id(MP(b.fi+j, b.se-1))>=0)
			++cnt;
	return cnt<=1;
}
void set_valid(int i, bool v) {
	if(v==valid[i])
		return;
	valid[i]=v;
	if(valid[i])
		valid_boxes.insert(i);
	else
		valid_boxes.erase(i);
}
void update_valid(int i) {
	PII b=boxes[i];
	bool important=false;
	forint(j, -1, 1)
		if(is_dangerous(MP(b.fi+j, b.se+1)))
			important=true;
	//printf("i=%d imp=%d\n",i,important);
	set_valid(i, !important);
}
void update_valid(PII b) {
	int i=get_box_id(b);
	if(i<0) return;
	update_valid(i);
}

int main() {
	int n; scanf("%d", &n);
	box_id.clear();
	forn(i, n) {
		scanf("%d%d", &boxes[i].fi, &boxes[i].se);
		box_id[boxes[i]]=i;
	}

	fillchar(valid, false);
	valid_boxes.clear();
	forn(i, n) update_valid(i);

	LL ans=0;
	forn(i, n) {
	//printf("i=%d vn=%d\n",i,valid_boxes.size());
		int cur;
		if(i%2==0) cur=*valid_boxes.rbegin();
			else cur=*valid_boxes.begin();
		valid_boxes.erase(cur);
		PII b=boxes[cur];
		box_id[b]=-1;
		forint(j, -2, 2) {
			update_valid(MP(b.fi+j, b.se));
			update_valid(MP(b.fi+j, b.se-1));
		}
		ans=(ans*n+cur)%LL(1e9+9);
	}
	printf("%d\n", (int)ans);

	return 0;
}