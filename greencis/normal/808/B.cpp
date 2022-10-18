#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;

int main()
{
    int n, k;
    cin >> n >> k;
    ll sum = 0, all = 0;
    queue<int> q;
    for (int i = 0; i < k; ++i) {
        int x;
        cin >> x;
        sum += x;
        q.push(x);
    }
    all += sum;
    for (int i = 0; i < n - k; ++i) {
        int x;
        cin >> x;
        sum -= q.front();
        q.pop();
        q.push(x);
        sum += x;
        all += sum;
    }
    cout << setprecision(17) << fixed << all / ld(n - k + 1) << endl;

    return 0;
}