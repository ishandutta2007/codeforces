#include <bits/stdc++.h>
using namespace std;
string a;
inline int query(string x) {
    cout << "? " << x << endl;
    int cnt;
    cin >> cnt;
    for (int i = 0; i < cnt; i++) {
        int pos;
        cin >> pos;
        for (int j = 0; j < x.size(); j++) {
            a[pos + j - 1] = x[j];
        }
    }
    return cnt;
}
inline string solve() {
    int n;
    cin >> n;
    a = string(n, '?');
    if (n == 4) {
        query("CH");
        query("CO");
        query("HC");
        query("HO");
        int cnt = 0;
        for (auto i : a) cnt += i == '?';
        if (cnt == 4) {
            query("OOO");
            query("HHH");
            query("CCC");
            int cnt = 0;
            for (auto i : a) cnt += i == '?';
            if (cnt == 4) {
                query("OOHH");
                return a[0] == '?' ? "OOCC" : "OOHH";
            }
            if (cnt == 0) return a;
            if (a == "OOO?") return query("OOOH") ? "OOOH" : "OOOC";
            a[0] = 'O';
            return a;
        }
        else {
            int pos;
            for (pos = 0; ; pos++) if (a[pos] != '?') break;
            string now = a.substr(pos, 2);
            if (pos == 0) {
                query(now + 'O');
                query(now + 'H');
                if (a[2] == '?') a[2] = 'C';
                now += a[2];
                query(now + 'O');
                query(now + 'H');
                if (a[3] == '?') a[3] = 'C';
            }
            else if (pos == 2) {
                query('O' + now);
                query('H' + now);
                if (a[1] == '?') a[1] = 'C';
                now = a[1] + now;
                query('O' + now);
                query('H' + now);
                if (a[0] == '?') a[0] = 'C';
            }
            else {
                query(now + 'O');
                query(now + 'H');
                if (a[3] == '?') a[3] = 'C';
                now += a[3];
                query('O' + now);
                query('H' + now);
                if (a[0] == '?') a[0] = 'C';
            }
            return a;
        }
    }
    else {
        query("CH");
        query("CO");
        query("CC");
        query("HH");
        query("OH");
        for (int i = 1; i < n - 1; i++) if (a[i] == '?') a[i] = 'O';
        string now = a.substr(1, n - 2);
        if (a[0] == '?') {
            query('O' + now);
            if (a[0] == '?') a[0] = 'H';
        }
        if (a[n - 1] == '?') {
            query(now + 'O');
            if (a[n - 1] == '?') a[n - 1] = 'C';
        }
        return a;
    }
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        cout << "! " + solve() << endl;
        int x;
        cin >> x;
    }
}