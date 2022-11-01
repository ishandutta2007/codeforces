#include <bits/stdc++.h>
#define N 200050
using namespace std;
typedef pair<int,int> pii;
typedef long long LL;
LL ans;
int c[N],w[N],flag[N],n,m;
priority_queue<pii, vector<pii>, greater<pii> > q;
inline int rd() {int r;scanf("%d",&r);return r;}
int main() {
	n = rd(), m = rd();
	for (int i=1;i<=n;i++) c[i] = rd();
	for (int i=1;i<=n;i++) w[i] = rd();
	
	for (int i=1;i<=n;i++) {
		int cur = c[i] % 100;
		if (!cur) continue;
		q.push(pii((100-cur) * w[i], i));
		if (m >= cur)
			m -= cur;
		else {
			pii tmp = q.top(); q.pop();
			ans += tmp.first;
			flag[ tmp.second ] = 1;
			m += 100;
			m -= cur;
		}
	}
	cout << ans << endl;
	for (int i=1;i<=n;i++) {
		int t = c[i] / 100;
		if (flag[i])
			printf("%d %d\n",t+1, 0);
		else
			printf("%d %d\n",t, c[i]-100*t);
	}

	return 0;
}