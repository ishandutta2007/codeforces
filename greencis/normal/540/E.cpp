#include <bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<ld,ld>
using namespace std;
typedef long long ll;
typedef long double ld;

int n,a,b;
map<int,int> mp;
int x[300005],xi,y[300005];
ll ans;

void merge_sort(int l, int r) {
    if (l == r) return;
    int mid = (l + r) >> 1;
    merge_sort(l, mid);
    merge_sort(mid+1, r);
    int ai = l, bi = mid + 1, ci = l;
    while (ci <= r) {
        if (bi <= r && (ai > mid || x[ai] > x[bi])) y[ci++] = x[bi++];
        else {
            ans += ll(bi - mid - 1);
            y[ci++] = x[ai++];
        }
    }
    for (int i = l; i <= r; ++i)
        x[i] = y[i];
}

vector< pii > pairs;

int cntR(int num) {
    int L = 0, R = (int)pairs.size() - 1;
    while (L < R) {
        int mid = (L + R + 1) >> 1;
        if (pairs[mid].first <= num) L = mid;
        else R = mid - 1;
    }
    if (L == R && pairs[L].first <= num) return L + 1;
    else return 0;
}

int main()
{
    scanf("%d",&n);
    while (n--) {
        scanf("%d%d",&a,&b);
        if (!mp[a]) mp[a] = a;
        if (!mp[b]) mp[b] = b;
        swap(mp[a], mp[b]);
    }

    for (map<int,int>::iterator it = mp.begin(); it != mp.end(); ++it)
        if (it->first != it->second) {
            pairs.push_back(*it);
            x[xi++] = it->second;
        }
    while (xi < 1 || (xi & (xi - 1)))
        x[xi++] = 2e9;

    merge_sort(0, xi-1);
    for (int i = 0; i < pairs.size(); ++i) {
        if (pairs[i].first < pairs[i].second) {
            ans += pairs[i].second - pairs[i].first + 1 - (cntR(pairs[i].second) - cntR(pairs[i].first - 1));
        } else {
            ans += pairs[i].first - pairs[i].second + 1 - (cntR(pairs[i].first) - cntR(pairs[i].second - 1));
        }
    }

    cout << ans;

    return 0;
}