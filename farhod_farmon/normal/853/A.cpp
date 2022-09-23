#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")

#define fi first
#define se second

const int N = 300300;

using namespace std;

int n, k;
int a[N];
int b[N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(0);

        cin >> n >> k;
        long long res = 0;
        for(int i = 1; i <= n; i++) cin >> a[i];

        set < pair < int, int > > s;
        vector < int > v;
        long long sum = 0;
        for(int i = 1; i <= k; i++){
                res += (k - i + 1) * 1ll * a[i];
                s.insert({a[i], i});
                sum += a[i];
        }
        for(int i = 1; i <= n; i++){
                if(i + k <= n){
                        s.insert({a[i + k], i + k});
                        sum += a[i + k];
                }
                v.push_back((--s.end())->se);
                s.erase(--s.end());
                sum -= a[v.back()];
                res += sum;
        }
        cout << res << "\n";
        for(int i = 0; i < n; i++) b[v[i]] = k + i + 1;
        for(int i = 1; i <= n; i++)cout << b[i] << " ";
}