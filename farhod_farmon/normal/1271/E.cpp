#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 3030;
const int mod = 1e9 + 7;

using namespace std;

long long n, k;

vector < int > get(long long x)
{
        vector < int > res;
        for(int i = 60; i >= 0; i--){
                res.push_back((x >> i) & 1ll);
        }
        return res;
}

long long comp(vector < int > a, vector < int > b, int l)
{
        for(int i = 0; i < a.size() - l; i++){
                if(a[i] < b[i]){
                        return (1ll << l);
                } else if(a[i] > b[i]){
                        return 0;
                }
        }
        long long res = 1;

        for(int i = a.size() - l; i < a.size(); i++){
                if(b[i] == 1){
                        res += (1ll << a.size() - i - 1);
                }
        }
        return res;
}

long long solve(vector < int > a, vector < int > b)
{
        long long res = 0;
        int st = 1;
        if(a.back() == 0){
                st = 2;
                res += comp(a, b, 1);
        } else{
                res = 1;
                for(int i = 0; i < a.size(); i++){
                        if(a[i] < b[i]){
                                break;
                        } else if(a[i] > b[i]){
                                res = 0;
                                break;
                        }
                }
        }

        for(int i = st; a[0] != 1; i++){
                vector < int > na;
                for(int i = 1; i < a.size(); i++){
                        na.push_back(a[i]);
                }
                na.push_back(0);
                a = na;

                res += comp(a, b, i);
        }

        return res;
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> k;

        auto B = get(n);
        long long res = 0;
        for(int i = 59; i >= 0; i--){
                res += (1ll << i);
                if(solve(get(res), B) < k){
                        res -= (1ll << i);
                }
        }

        cout << res << "\n";
}