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

char s[105], t[105];
int ti, n;

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n >> s;
    for (int i = 0; i < n; ++i) {
        if (is_vowel(s[i]) && ti && is_vowel(t[ti - 1]))
            continue;
        t[ti++] = s[i];
    }
    t[ti] = 0;
    cout << t << endl;

    return 0;
}