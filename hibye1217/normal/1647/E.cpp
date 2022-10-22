#include <bits/stdc++.h>
#define endl '\n'
#define PRECISION 0
using namespace std;
using ll = long long;
using ld = long double;
#define fr first
#define sc second
using pi2 = pair<int, int>;
using pl2 = pair<ll, ll>;
#define all(v) v.begin(), v.end()
#define unq(v) sort( all(v) ); v.erase( unique( all(v) ), v.end() );
typedef pair<pi2, pi2> pi4;

const int N = 30;
int ptr[100020], arr[100020], ans[100020];
int spr[100020][32], res[100020];
bool chk[100020], flg[100020];
const int M = 131072, INF = 1e9;
int seg[262150];

void upd(int pos, int val){ pos += M-1;
	seg[pos] = val; pos >>= 1;
	while (pos){
		seg[pos] = min(seg[pos<<1], seg[pos<<1|1]);
		pos >>= 1;
	}
}
int rmq(int st, int ed){ st += M-1; ed += M-1;
	int res = INF;
	while (st <= ed){
		if (st & 1){ res = min(res, seg[st]); st += 1; }
		if (~ed & 1){ res = min(res, seg[ed]); ed -= 1; }
		if (st > ed){ break; }
		st >>= 1; ed >>= 1;
	}
	return res;
}

void Main(){
	for (int i = 1; i <= M; i++){ upd(i, INF); }
	int n; cin >> n;
	int cnt = 0;
	for (int i = 1; i <= n; i++){
		cin >> ptr[i]; spr[i][0] = ptr[i];
		if (chk[ ptr[i] ]){ cnt += 1; } chk[ ptr[i] ] = 1;
		upd(i, i);
	}
	int mx = 0;
	for (int i = 1; i <= n; i++){
		cin >> arr[i]; mx = max(mx, arr[i]);
		if (arr[i] <= n){ upd(arr[i], INF); }
	}
	int m = (mx-n) / cnt;
	//cout << "M " << m << "   " << mx << ' ' << n << ' ' << cnt << endl;
	for (int j = 1; j <= N; j++){
		for (int i = 1; i <= n; i++){ spr[i][j] = spr[ spr[i][j-1] ][j-1]; }
	}
	for (int i = 1; i <= n; i++){
		int bit = m, now = i;
		for (int j = N; j >= 0; j--){
			if (bit & 1<<j){ now = spr[now][j]; }
		}
		res[i] = now;
	}
	for (int idx = 1; idx <= n; idx++){
		int num = res[idx];
		if (!flg[num]){ ans[idx] = arr[num]; flg[num] = 1; }
		else{
			int val = rmq(arr[num]+1, M);
			ans[idx] = val; upd(val, INF);
		}
	}
	for (int i = 1; i <= n; i++){ cout << ans[i] << ' '; }
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout.setf(ios::fixed);
	cout.precision(PRECISION);
	Main();
}