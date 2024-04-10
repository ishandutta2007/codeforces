#include <bits/stdc++.h>
#define endl '\n'
#define PRECISION 0
using namespace std;
#define fr first
#define sc second
using pi2 = pair<int, int>;
typedef pair<pi2, pi2> pi4;
using ll = long long;
using pl2 = pair<ll, ll>;

const int N = 100;
int ant[120], bnt[120];

void Main(){
	int n; cin >> n;
	while (n--){ int x; cin >> x; ant[x] += 1; }
	int m; cin >> m;
	while (m--){ int x; cin >> x; bnt[x] += 1; }
	int ap=1, bp=1;
	int ans = 0;
	while (ap <= N && bp <= N){
		if (ant[ap] && bnt[bp]){ ans += 1; ant[ap] -= 1; bnt[bp] -= 1; }
		if (!ant[ap]){ ap += 1; } if (!bnt[bp]){ bp += 1; }
		if (ap+1 < bp){ ap = bp-1; } if (bp+1 < ap){ bp = ap-1; }
	}
	cout << ans;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout.setf(ios::fixed);
	cout.precision(PRECISION);
	Main();
}