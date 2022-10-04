#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    vector <int> who(n + 1, -1);
    int uk = 1;
    for (int i = 2; i <= n; ++i) {
    	if (who[i] == -1) {
    		who[i] = uk++;
    		for (int j = 2 * i; j <= n; j += i) {
    			if (who[j] == -1) who[j] = who[i];
    		}
    	}
    }
    for (int i = 2; i <= n; ++i) {
    	cout << who[i] << ' ';
    }
}