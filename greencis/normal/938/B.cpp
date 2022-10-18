#include <bits/stdc++.h>
#ifndef LOCAL
#define cerr if(0)cerr
#endif // LOCAL
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

string z = "aeiouy";
bool is_vowel(char c) { return z.find(c) != string::npos; }

int n, x, ans = 0;

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n;
    while (n--) {
        cin >> x;
        ans = max(ans, min(x - 1, 1000000 - x));
    }
    cout << ans;

    return 0;
}