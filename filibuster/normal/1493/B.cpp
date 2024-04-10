#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
using matr = vector<vi>;

const int INF = 1e9 + 13;


/*
4 5
0 1
1 2
2 3
3 4

1 6
4 4
*/

int get1(int x) {
    if(x == 0 || x == 1 || x == 8)
        return x;
    else
        return 7 - x;
}

int get2(int x) {
    int y = get1(x % 10) * 10 + get1(x / 10);
    return y;
}

string get3(int x) {
    string s = "";

    s += char(x / 10 + '0');
    s += char(x % 10 + '0');

    return s;
}

void solve() {
    int h, m;
    cin >> h >> m;

    string s;
    cin >> s;

    int a = (s[0] - '0') * 10 + s[1] - '0';
    int b = (s[3] - '0') * 10 + s[4] - '0';

    while(true) {
        set<int> st;
        st.insert(a % 10);
        st.insert(b % 10);
        st.insert(a / 10);
        st.insert(b / 10);

        bool res = true;
        if(st.count(3) + st.count(4) + st.count(6) + st.count(7) + st.count(9)) {
            res = false;
        }

        if(res) {
            int a1 = get2(b);
            int b1 = get2(a);

            if(a1 < h && b1 < m) {
                cout << get3(a) << ":" << get3(b) << endl;
                return;
            }
        }


        b++;
        if(b == m) {
            b = 0;
            a++;
            if(a == h) {
                a = 0;
            }
        }
    }
}

int main() {


    int t = 1;
    cin >> t;

    while(t--)
        solve();
}