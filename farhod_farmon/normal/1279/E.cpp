#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 55;
const long long mod = 998244353;

using namespace std;

long long d[N];
long long fac[N];

long long F(int n)
{
        if(n <= 0){
                return 1;
        }
        return fac[n];
}

long long get3(vector < int > v)
{
        if(v.back() != -1){
                return 1;
        }
        int n = v.size();
        vector < int > used(n, 0);

        int rem = n;

        for(int i = 0; i < n; i++){
                rem -= (v[i] != -1);
                if(used[i] || v[i] == -1){
                        continue;
                }
                int j = i;
                while(!used[j]){
                        used[j] = true;
                        j = v[j];
                        if(j == -1){
                                break;
                        }
                }
                if(i == j){
                        return 0;
                }
        }

        return fac[rem - 1];
}

vector < int > get2(int n, long long need)
{
        if(n == 1){
                return {1};
        } else if(n == 2){
                return {2, 1};
        }

        //cout << n << " " << need << endl;

        set < int > rem;
        for(int i = 0; i < n - 1; i++){
                rem.insert(i);
        }
        vector < int > res(n, -1);
        res[0] = n - 1;
        for(int i = 1; i < n; i++){
                for(auto x: rem){
                        res[i] = x;
                        long long col = get3(res);
                        if(col <= need){
                                need -= col;
                                continue;
                        } else{
                                break;
                        }
                }
                rem.erase(res[i]);
        }
        for(int &x: res){
                x += 1;
                //cout << x << " ";
        }
        //cout << endl;
        return res;
}

vector < int > get(int n, long long need)
{
        if(n == 0){
                return {};
        } else if(n == 1){
                assert(need == 0);
                return {1};
        }

        int base = -1;
        for(int i = 1; i <= n; i++){
                need -= F(i - 2) * d[n - i];
                if(need < 0){
                        need += F(i - 2) * d[n - i];
                } else{
                        continue;
                }
                base = i;
                break;
        }
        assert(base != -1);
        long long A = need / d[n - base], B = need % d[n - base];

        auto res = get2(base, A);
        auto shit = get(n - base, B);

        for(int x: shit){
                res.push_back(x + base);
        }

        return res;
}

void solve()
{
        int n;
        long long k;
        cin >> n >> k;

        int base = 0;
        if(n > 22){
                base = n - 22;
                n = 22;
        }

        if(d[n] < k){
                cout << -1 << "\n";
                return;
        }

        k -= 1;

        auto A = get(n, k);
        vector < int > res;
        for(int i = 1; i <= base; i++){
                res.push_back(i);
        }
        for(int x: A){
                res.push_back(x + base);
        }
        for(int x: res){
                cout << x << " ";
        }
        cout << "\n";
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(0);

        fac[0] = 1;
        for(int i = 1; i < N; i++){
                fac[i] = fac[i - 1] * i;
        }

        d[0] = 1;
        for(int i = 1; i < N; i++){
                for(int j = 1; j <= i; j++){
                        d[i] += d[i - j] * F(j - 2);
                }
        }

        int T;
        cin >> T;
        while(T--){
                solve();
        }
}