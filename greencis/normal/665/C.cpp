#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;

char s[200105];
int n;

inline char first(char a, char b) {
    return a == 'a' || b == 'a' ? (a == 'b' || b == 'b' ? 'c' : 'b') : 'a';
}

int main()
{
    cin >> s;
    n = strlen(s);
    for (int i = 1; i < n; ++i) {
        if (s[i] == s[i - 1])
            s[i] = first(s[i - 1], s[i + 1]);
    }
    cout << s;

    return 0;
}