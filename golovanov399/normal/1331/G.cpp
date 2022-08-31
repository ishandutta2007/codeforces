#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

void f(int n) {
	cout << "f(" << n << ") = ";
	if (n < 0) {
		cout << "-";
	}
	if (n == 4) cout << "322.00\n"; else
	if (n == 3) cout << "136.73\n"; else
	if (n == 2) cout << "41.41\n"; else
	if (n == 1) cout << "6.00\n"; else
	if (n == 0) cout << "0.00\n"; else
	if (n == -1) cout << "4.00\n"; else
	if (n == -2) cout << "38.59\n"; else
	if (n == -3) cout << "133.27\n"; else
	if (n == -4) cout << "318.00\n"; else
	if (n == -5) cout << "622.76\n"; else
	if (n == -6) cout << "1077.55\n"; else
	if (n == -7) cout << "1712.35\n"; else
	if (n == -8) cout << "2557.17\n"; else
	if (n == -9) cout << "3642.00\n"; else
	if (n == -10) cout << "4996.84\n"; else
	if (n == -11) cout << "6651.68\n"; else
	if (n == -12) cout << "8636.54\n"; else
	if (n == -13) cout << "10981.39\n"; else
	if (n == -14) cout << "13716.26\n"; else
	if (n == -15) cout << "16871.13\n"; else
	if (n == -16) cout << "20476.00\n"; else
	if (n == -17) cout << "24560.88\n"; else
	if (n == -18) cout << "29155.76\n"; else
	if (n == -19) cout << "34290.64\n"; else
	if (n == -20) cout << "39995.53\n"; else
	if (n == -21) cout << "46300.42\n"; else
	if (n == -22) cout << "53235.31\n"; else
	if (n == -23) cout << "60830.20\n"; else
	if (n == -24) cout << "69115.10\n"; else
	if (n == -25) cout << "78120.00\n"; else
	if (n == -26) cout << "87874.90\n"; else
	if (n == -27) cout << "98409.80\n"; else
	if (n == -28) cout << "109754.71\n"; else
	if (n == -29) cout << "121939.61\n"; else
	if (n == -30) cout << "134994.52\n"; else
	if (n == -31) cout << "148949.43\n"; else
	if (n == -32) cout << "163834.34\n"; else
	if (n == -33) cout << "179679.26\n"; else
	if (n == -34) cout << "196514.17\n"; else
	if (n == -35) cout << "214369.08\n"; else
	if (n == -36) cout << "233274.00\n"; else
	if (n == -37) cout << "253258.92\n"; else
	if (n == -38) cout << "274353.84\n"; else
	if (n == -39) cout << "296588.76\n"; else
	if (n == -40) cout << "319993.68\n"; else
	if (n == -41) cout << "344598.60\n"; else
	if (n == -42) cout << "370433.52\n"; else
	if (n == -43) cout << "397528.44\n"; else
	if (n == -44) cout << "425913.37\n"; else
	if (n == -45) cout << "455618.29\n"; else
	if (n == -46) cout << "486673.22\n"; else
	if (n == -47) cout << "519108.14\n"; else
	if (n == -48) cout << "552953.07\n"; else
	if (n == -49) cout << "588238.00\n"; else
	if (n == -50) cout << "624992.93\n"; else
	cout << "MAGNA NIMIS!\n";
}

int main() {
	vector<int> a;
	int n;
	while (cin >> n) {
		a.push_back(n);
	}
	while (!a.empty()) {
		f(a.back());
		a.pop_back();
	}

	return 0;
}