#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <array>
typedef long long ll;
using namespace std;

const ll inf = 1e18 + 128;
const string f0 = "What are you doing at the end of the world? Are you busy? Will you save us?";
const string f11 = "What are you doing while sending \"";
const string f12 = "\"? Are you busy? Will you send \"";
const string f13 = "\"?";
const int maxn = 1e5 + 128;
vector<ll> len(maxn, 0);
int maxi = maxn;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    len[0] = f0.size();
    for (int i = 1; i < maxn; i++)
    {
        len[i] = len[i - 1] * 2 + (ll)(f11.size() + f12.size() + f13.size());
        if (len[i] >= inf)
        {
            len[i] = inf;
            maxi = min(maxi, i);
        }
    }
    int t;
    cin >> t;
    string ans;
    while (t--)
    {
        int n; ll k;
        cin >> n >> k; k--;
        if (k >= len[n])
            ans.push_back('.');
        else
        {
            bool added = false;
            for (int i = n; i > 0; i--)
            {
                if (k < f11.size())
                {
                    ans.push_back(f11[k]);
                    added = true;
                    break;
                }
                k -= f11.size();
                if (k < len[i - 1])
                {
                    continue;
                }
                k -= len[i - 1];
                if (k < f12.size())
                {
                    ans.push_back(f12[k]);
                    added = true;
                    break;
                }
                k -= f12.size();
                if (k < len[i - 1])
                {
                    continue;
                }
                k -= len[i - 1];
                if (k < f13.size())
                {
                    ans.push_back(f13[k]);
                    added = true;
                    break;
                }
            }
            if (!added) ans.push_back(f0[k]);
        }
    }
    cout << ans << "\n";
    return 0;
}