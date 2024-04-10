#include<bits/stdc++.h>
using namespace std;
#define int long long
int getl(string &s, char c) {
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == c) return i;
    }   
    return s.size();
}   
int getr(string &s, char c) {
    for (int i = (int)s.size() - 1; i >= 0; --i) {
        if (s[i] == c) return i;
    }   
    return -1;
}   
int get2(string s) {
    int ans = 0;
    for (char c : s) {
        ans += c == '|';
    }
    return ans;  
}   
int get1(string s) {
    int p1 = getl(s, ':');
    int p2 = getr(s, ':');
    if (p2 <= p1) {
        cout << "-1\n";
        exit(0);
    }   
    return get2(s.substr(p1 + 1, p2 - p1 - 1)) + 2;
}   
signed main() {
    #ifdef HOME
        freopen("input.txt", "r", stdin);
    #else
        ios_base::sync_with_stdio(0); cin.tie(0); cout.precision(20);
    #endif
    string s;
    cin >> s;
    int p1 = getl(s, '[');
    int p2 = getr(s, ']');
    if (p2 < p1) {
        cout << "-1\n";
        exit(0);
    }   
    cout << get1(s.substr(p1 + 1, p2 - p1 - 1)) + 2 << '\n';
}