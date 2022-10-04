#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

vector <string> week = {"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};

vector <int> cnt = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int get(string s) {
    for (int i = 0; i < 7; ++i) {
        if (week[i] == s) return i;
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    string a, b;
    cin >> a >> b;
    int id1 = get(a);
    int id2 = get(b);
    for (int i = 0; i < 11; ++i) {
        if ((id1 + (cnt[i] % 7)) % 7 == id2) {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
}