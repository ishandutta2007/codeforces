#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

bool prime(int x) {
    for (int d = 2; d * d <= x; ++d) {
        if (x % d == 0) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    vector <int> sp = {2, 3, 5, 7};
    int dv = -1;
    for (int i = 0; i < 4; ++i) {
        cout << sp[i] << endl;
        string s;
        cin >> s;
        if (s == "yes") {
            dv = sp[i];
            break;
        }
    }
    if (dv == -1) {
        cout << "prime" << endl;
        return 0;
    }
    for (int x = dv; x <= 100; ++x) {
        if (prime(x) && dv * x <= 100) {
            cout << dv * x << endl;
            string s;
            cin >> s;
            if (s == "yes") {
                cout << "composite" << endl;
                return 0;
            }
        }
    }
    cout << "prime" << endl;
}