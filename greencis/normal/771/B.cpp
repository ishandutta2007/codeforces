#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

string s[105], cur = "Aa", tmp;

string nxt(string x) {
    ++x[1];
    if (x[1] > 'z') {
        ++x[0];
        x[1] = 'a';
    }
    return x;
}

int main()
{
    ios_base::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    for (int i = 0; i < k - 1; ++i) {
        s[i] = cur;
        cur = nxt(cur);
        cout << s[i] << " ";
    }
    for (int i = k - 1; i < n; ++i) {
        cin >> tmp;
        if (tmp == "YES")
            s[i] = cur;
        else
            s[i] = s[i - k + 1];
        cur = nxt(cur);
        cout << s[i] << " ";
    }
    cout << endl;

    return 0;
}