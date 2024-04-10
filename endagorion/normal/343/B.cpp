#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()


using namespace std;

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    string s;
    cin >> s;
    vector<char> st;
    int N = s.size();
    for (int i = 0; i < N; ++i) {
        if (st.empty() || s[i] != st.back()) {
            st.pb(s[i]);
        } else {
            st.pop_back();
        }
    }
    cout << (st.empty() ? "Yes\n" : "No\n");

    return 0;
}