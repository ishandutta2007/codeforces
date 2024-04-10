#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

string a;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> a;
    string b = a;
    reverse(b.begin(), b.end());
    a += b;
    cout << a << endl;
    return 0;
}