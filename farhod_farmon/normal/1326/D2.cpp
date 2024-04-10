#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 1000100;
const long long mod = 998244353;

using namespace std;

int n;
string s;

vector < int > g1(string s)
{
        vector<int> d1 (n);
int l=0, r=-1;
for (int i=0; i<n; ++i) {
  int k = i>r ? 1 : min (d1[l+r-i], r-i+1);
  k = max(k - 1, 1);
  while (i+k < n && i-k >= 0 && s[i+k] == s[i-k])  ++k;
  d1[i] = k;
  if (i+k-1 > r)
    l = i-k+1,  r = i+k-1;
}
return d1;
}

vector < int > g2(string s)
{
        vector<int> d2 (n);
int l=0, r=-1;
for (int i=0; i<n; ++i) {
  int k = i>r ? 0 : min (d2[l+r-i+1], r-i+1);
  k = max(k - 1, 0);
  while (i+k < n && i-k-1 >= 0 && s[i+k] == s[i-k-1])  ++k;
  d2[i] = k;
  if (i+k-1 > r)
    l = i-k,  r = i+k-1;
}
return d2;
}

int d[N];
int f[N];
int inf = 1e9;

void solve()
{
        cin >> s;
        n = s.size();

        auto d1 = g1(s);
        auto d2 = g2(s);


        int best = 1, pre = 0, l = 1, r = 0;

        for(int i = 0; i <= s.size() + 1; i++) d[i] = f[i] = -inf;

        for(int i = 0; i < s.size(); i++){
                int l = i - d1[i] + 1, r = i + d1[i] - 1;
                if(l <= n - r - 1)d[l] = max(d[l], r - l + 1);
                if(l >= n - r - 1)f[r] = max(f[r], r - l + 1);
        }
        for(int i = 0; i < s.size(); i++){
                if(!d2[i]) continue;
                int l = i - d2[i], r = i + d2[i] - 1;
                if(l <= n - r - 1)d[l] = max(d[l], r - l + 1);
                if(l >= n - r - 1)f[r] = max(f[r], r - l + 1);
        }

        for(int i = 0; i < n / 2; i++){
                if(i > 0) d[i] = max(d[i - 1] - 2, d[i]);
                if(i * 2 + d[i] > best){
                        best = i * 2 + d[i];
                        pre = i;
                        l = d[i];
                        r = 0;
                }

                if(s[i] != s[n - i - 1]) break;
        }
        for(int i = n - 1; i >= n / 2; i--){
                f[i] = max(f[i + 1] - 2, f[i]);
                if((n - i - 1) * 2 + f[i] > best){
                        best = (n - i - 1) * 2 + f[i];
                        pre = n - i - 1;
                        l = 0;
                        r = f[i];
                }

                if(s[i] != s[n - i - 1]) break;
        }

        string res = "";
        for(int i = 0; i < pre; i++) res += s[i];
        for(int i = 0; i < l; i++) res += s[pre + i];
        for(int i = 0; i < r; i++) res += s[n - 1 - pre - i];
        for(int i = pre - 1; i >= 0; i--) res += s[i];
        cout << res << '\n';
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(0);

        int t;
        cin >> t;
        while(t--) solve();
}