#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <long long, long long> pii;

priority_queue <pii, vector <pii>, greater <pii> > q;

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		int x; scanf("%d", &x);
		q.push(mp((long long)x, (long long)i));
	}
	vector <pii> ans;
	while (q.size() > 1){
//		cout << "size:" << q.size() << endl;
		pii x = q.top(); q.pop();
		pii y = q.top(); q.pop();
//		cout << "  x:" << x.fi << " " << x.se << endl;
//		cout << "  y:" << y.fi << " " << y.se << endl;
		if (x.fi != y.fi){
			ans.push_back(mp(x.se, x.fi));
			q.push(y);
			continue;
		}
		y.fi += x.fi;
		q.push(y);
	}
	pii x = q.top();
	ans.push_back(mp(x.se, x.fi));
	sort(ans.begin(), ans.end());
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++){
		printf("%I64d ", ans[i].se);
	}
	printf("\n");
	return 0;
}