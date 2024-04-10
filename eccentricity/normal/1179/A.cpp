//Author: SBHeltion
//Date: 2019-06-22
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 120000;
int dq[maxn << 2];
int qhead = 0, qtail = 0;
int ansA[maxn << 2], ansB[maxn << 2];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(12);
	int n, q, ma = 0;
	cin >> n >> q;
	for(int i = 1; i <= n; i += 1){
		int a;
		cin >> a;
		dq[qtail ++] = a;
		ma = max(ma, a);
	}
	int t = 0;
	while(dq[qhead] != ma){
		t += 1;
		ansA[t] = dq[qhead], ansB[t] = dq[qhead + 1];
		int d = max(ansA[t], ansB[t]), x = min(ansA[t], ansB[t]);
		dq[qhead += 1] = d;
		dq[qtail ++] = x;
	}
	for(int i = 1; i <= q; i += 1){
		LL m;
		cin >> m;
		if(m <= t) cout << ansA[m] << " " << ansB[m] << "\n";
		else{
			int o = (m - t) % (n - 1);
			if(o == 0) o = n - 1;
			cout << ma << " " << dq[qhead + o] << "\n";
		}
	}
	return 0;
}