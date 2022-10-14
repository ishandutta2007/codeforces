#include <set>
#include <cstdio>
#include <utility>
#include <algorithm>

using namespace std;

const int N = 222222;

int n;
pair<int, int> p[N];
set<pair<int, int> > a;

void solve(int l, int r){
	if(r - l > 1){
		int m = (l + r) >> 1;
		for(int i = l; i < r; ++ i){
			a.insert(make_pair(p[m].first, p[i].second));
		}
		solve(l, m);
		solve(m + 1, r);
	}
}

int main(){
	scanf("%d", &n);
	a.clear();
	for(int i = 0; i < n; ++ i){
		int x, y;
		scanf("%d%d", &x, &y);
		p[i] = make_pair(x, y);
		a.insert(p[i]);		
	}
	sort(p, p + n);
	solve(0, n);
	printf("%d\n", (int)a.size());
	for(set<pair<int, int> >::iterator iter = a.begin(); iter != a.end(); ++ iter){
		printf("%d %d\n", iter->first, iter->second);
	}
	return 0;
}