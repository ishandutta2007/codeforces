#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

char get(string a, string b) {
	if ((a[0] == 'a' || a[1] == 'a') && (b[0] == 'a' || b[1] == 'a')) return 'a'; 
	if ((a[0] == 'b' || a[1] == 'b') && (b[0] == 'b' || b[1] == 'b')) return 'b'; 
	if ((a[0] == 'c' || a[1] == 'c') && (b[0] == 'c' || b[1] == 'c')) return 'c'; 
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    string s;
    cin >> s;
    string a, b;
    int n = s.size();
    int l = 0, r = n - 1;
    while (l < r) {
    	if (r - l + 1 <= 3) {
    		a += s[l];
    	} else {
    		string fr;
    		fr += s[l];
    		fr += s[l + 1];
    		string sc;
    		sc += s[r - 1];
    		sc += s[r];
    		a += get(fr, sc);
    		b += get(fr, sc);
    	}
    	l += 2;
    	r -= 2;
    }
    reverse(b.begin(), b.end());
    a += b;
    for (auto c : a) cout << c;
}