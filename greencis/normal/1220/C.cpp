#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

string s;
int n;

int main() {
    ios_base::sync_with_stdio(false);

    cin >> s;
    n = s.size();
    set<int> st;
    for (int i = 0; i < n; ++i) {
        auto it = st.upper_bound(-(int)s[i]);
        if (it == st.end()) cout << "Mike\n";
        else cout << "Ann\n";
        st.insert(-(int)s[i]);
    }
}