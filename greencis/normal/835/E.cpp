#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, x, y;

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n >> x >> y;
    vector<int> diff_bits;
    int bit = 0;
    for (; bit <= 9; ++bit) {
        vector<int> v;
        for (int i = 1; i <= n; ++i)
            if (i & (1 << bit))
                v.push_back(i);
        if (!v.size())
            break;
        cout << "? " << v.size();
        for (int i : v)
            cout << " " << i;
        cout << endl;
        int ans;
        cin >> ans;
        int expected = y ^ (v.size() % 2 == 0 ? x : 0);
        if (expected == ans)
            diff_bits.push_back(bit);
    }

    int cnt0 = 0, cnt1 = 0;
    int digit = 0;
    bit = diff_bits[0];
    for (int i = 1; i <= n; ++i)
        if (i & (1 << bit))
            ++cnt1;
        else
            ++cnt0;
    if (cnt1 < cnt0 && cnt1)
        digit = 1;
    vector<int> v;
    for (int i = 1; i <= n; ++i)
        if ((i >> bit) % 2 == digit)
            v.push_back(i);
    int L = 0, R = (int)v.size() - 1;
    while (L < R) {
        int mid = (L + R) >> 1;
        cout << "? " << mid + 1;
        for (int i = 0; i <= mid; ++i)
            cout << " " << v[i];
        cout << endl;
        int ans;
        cin >> ans;
        int expected = y ^ (mid % 2 == 1 ? x : 0);
        if (expected == ans)
            R = mid;
        else
            L = mid + 1;
    }
    int p1 = v[L];
    int p2 = p1;
    for (int b : diff_bits)
        p2 ^= (1 << b);
    if (p1 > p2)
        swap(p1, p2);
    cout << "! " << p1 << " " << p2 << endl;

    return 0;
}