#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 5050;
const int Q = 250200;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int cnt;
vector < int > v;

int get(int x)
{
        int g;
        cout << "? " << x << endl;
        cin >> g;
        cnt += 1;
        return g;
}

int more(int x)
{
        int g;
        cout << "> " << x << endl;
        cin >> g;
        cnt += 1;
        return g;
}

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        v.resize(n);
        for(int i = 0; i < n; i++){
                v[i] = i;
        }
        shuffle(v.begin(), v.end(), rng);
        int l = 0, r = 1e9;
        while(l < r){
                int m = (l + r) / 2;
                if(more(m)){
                        l = m + 1;
                }
                else{
                        r = m;
                }
        }
        vector < int > a;
        a.push_back(l);
        int gg = n;
        n = min(n, 60 - cnt);
        for(int i = 0; i < n; i++){
                a.push_back(get(v[i] + 1));
        }
        sort(a.begin(), a.end());
        int res = a[1] - a[0];
        for(int i = 2; i < a.size(); i++){
                res = __gcd(res, a[i] - a[i - 1]);
        }
        cout << "! " << l - res * (gg - 1) << " " << res << endl;
}