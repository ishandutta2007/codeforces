#include<bits/stdc++.h>
using namespace std;

int n;
string s, t;

int main() {
    cin >> n;
    cin >> s >> t;

    if(s[0] == s[1] && t[0] == t[1]) {
        cout <<"YES\n";
        for(int i=0; i<n; i++)
            cout << "abc";

        return 0;
    }

    if(s[0] == s[1]) {
        s = t;
        t[0] = s[1];
        t[1] = s[0];
        t.append(1, 'a' + 'b' + 'c' - t[0] - t[1]);

        cout <<"YES\n";
        for(int i=0; i<n; i++)
            cout << t;

        return 0;
    }

    if(t[0] == t[1]) {
        t[0] = s[1];
        t[1] = s[0];
        t.append(1, 'a' + 'b' + 'c' - t[0] - t[1]);

        cout <<"YES\n";
        for(int i=0; i<n; i++)
            cout << t;

        return 0;
    }

    if(s == t) {
        t[0] = s[1];
        t[1] = s[0];
        t.append(1, 'a' + 'b' + 'c' - t[0] - t[1]);

        cout <<"YES\n";
        for(int i=0; i<n; i++)
            cout << t;

        return 0;
    }

    if(s[0] == t[1] && t[0] == s[1]) {
        cout << "YES\n";
        string ret;
        ret.append(n, s[0]);
        ret.append(n, 'a' + 'b' + 'c' - t[0] - t[1]);
        ret.append(n, s[1]);
        cout << ret;
        return 0;
    }

    if(s[0] == t[0] || s[1] == t[0]) {
        s += t[1];
        reverse(s.begin(), s.end());

        cout << "YES\n";
        string ret;
        ret.append(n, s[0]);
        ret.append(n, s[1]);
        ret.append(n, s[2]);
        cout << ret;
        return 0;
    }

    if(t[1] == s[0]) {
        t += s[1];
        reverse(t.begin(), t.end());

        cout << "YES\n";
        string ret;
        ret.append(n, t[0]);
        ret.append(n, t[1]);
        ret.append(n, t[2]);
        cout << ret;
        return 0;
    }

    s[1] = t[0];
    s += t[1];

    reverse(s.begin(), s.end());

    cout << "YES\n";
    string ret;
    ret.append(n, s[0]);
    ret.append(n, s[1]);
    ret.append(n, s[2]);
    cout << ret;
    return 0;
}