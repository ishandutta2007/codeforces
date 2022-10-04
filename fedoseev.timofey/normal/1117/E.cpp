#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;


signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    //freopen("input.txt", "r", stdin);
    #endif
    string s;
    cin >> s;
    int n = s.size();
    int cnt = 0;
    vector <int> a, b, c;
    for (int i = 0; i < 26; ++i) {
     	for (int j = 0; j < 26; ++j) {
     	 	for (int k = 0; k < 26; ++k) {
     	 	 	++cnt;
     	 	 	if (cnt <= n) {
     	 	 	    a.push_back(i);
     	 	 	    b.push_back(j);
     	 	 	    c.push_back(k);
     	 	 	}	
     	 	}
     	}
    }
    string aa, bb, cc;
    for (auto x : a) aa.push_back(char(x + 'a'));
    for (auto x : b) bb.push_back(char(x + 'a'));
    for (auto x : c) cc.push_back(char(x + 'a'));

    cout << "? " << aa << endl;
    string r1;
    cin >> r1;
    cout << "? " << bb << endl;
    string r2;
    cin >> r2;
    cout << "? " << cc << endl;
    string r3;
    cin >> r3;
    vector <int> p(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
         	if (aa[i] == r1[j] && bb[i] == r2[j] && cc[i] == r3[j]) {
         	 	p[j] = i;
         	}
        }
    }
    string res(n, '$');
    for (int i = 0; i < n; ++i) {
    	res[p[i]] = s[i];	
 	}
 	cout << "! " << res << endl;
}