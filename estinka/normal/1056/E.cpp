#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

const ll base = 31, mod = 1000000087;
const int maxn = 1e6 + 128;
vector<ll> p(maxn, 1), h(maxn, 0);
ll hash_substr(int l, int r)
{
    return (mod + h[r + 1] - (h[l] * p[r + 1 - l]) % mod) % mod;
}
string s, t;
bool check(int len0, int len1)
{
    int pos = 0;
    ll h0 = -1, h1 = -1;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '0')
        {
            if (h0 == -1) h0 = hash_substr(pos, pos + len0 - 1);
            else if (hash_substr(pos, pos + len0 - 1) != h0) return false;
            pos += len0;
        }
        else
        {
            if (h1 == -1) h1 = hash_substr(pos, pos + len1 - 1);
            else if (hash_substr(pos, pos + len1 - 1) != h1) return false;
            pos += len1;
        }
    }
    if (len1 == len0 && h0 == h1) return false;
    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 1; i < maxn; i++) p[i] = (p[i - 1] * base) % mod;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    int num0 = count(s.begin(), s.end(), '0'), num1 = count(s.begin(), s.end(), '1');
    if (num0 < num1)
    {
        for (int i = 0; i < n; i++) s[i] = "10"[s[i] - '0'];
        swap(num0, num1);
    }
    for (int i = 0; i < t.size(); i++) h[i + 1] = (h[i] * base + (ll)(t[i] - 'a')) % mod;
    int ans = 0;
    for (int len0 = 1; len0 * num0 <= m; len0++)
    {
        int len1 = m - len0 * num0;
        if (len1 == 0 || len1 % num1 != 0) continue;
        len1 /= num1;
        ans += check(len0, len1);
        //if (check(len0, len1)) cout << len0 << " " << len1 << "\n";
    }
    cout << ans << "\n";
    return 0;
}