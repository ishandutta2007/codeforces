#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long double ld;
typedef long long ll;

int n,x,a,ans,cur;
vector< pii > pos,neg;

int main()
{
    cin >> n;
    while (n--) {
        cin >> x >> a;
        if (x < 0) {
            x = -x;
            neg.push_back(make_pair(x, a));
        } else {
            pos.push_back(make_pair(x, a));
        }
    }
    sort(neg.begin(), neg.end());
    sort(pos.begin(), pos.end());
    cur = 0;
    int posi = 0, negi = 0, iter = 0;
    while (1) {
        if (iter) {
            if (posi >= pos.size()) break;
            cur += pos[posi++].second;
        } else {
            if (negi >= neg.size()) break;
            cur += neg[negi++].second;
        }
        iter ^= 1;
    }
    ans = max(ans, cur);

    cur = 0;
    posi = 0, negi = 0, iter = 0;
    while (1) {
        if (!iter) {
            if (posi >= pos.size()) break;
            cur += pos[posi++].second;
        } else {
            if (negi >= neg.size()) break;
            cur += neg[negi++].second;
        }
        iter ^= 1;
    }
    ans = max(ans, cur);
    cout << ans;

    return 0;
}