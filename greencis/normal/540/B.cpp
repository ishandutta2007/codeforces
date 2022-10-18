#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;

int n,k,p,x,y,a,sum,l,r;
vector<int> ans;

int main()
{
    cin >> n >> k >> p >> x >> y;
    for (int i = 0; i < k; ++i) {
        cin >> a;
        sum += a;
        if (a >= y) ++r;
        else ++l;
    }
    x -= sum;
    for (int i = 0; i < n-k; ++i) {
        if (l >= r && x >= y) {
            x -= y;
            ans.push_back(y);
            ++r;
        } else if (l < r && x >= 1) {
            x -= 1;
            ans.push_back(1);
            ++l;
        }
    }

    if (l >= r || ans.size() != n - k) { cout << -1; return 0; }
    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i] << " ";

    return 0;
}