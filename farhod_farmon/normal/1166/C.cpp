#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 500500;
const int Q = 1 << 21;
const long long mod = 1e9 + 7;

using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        //freopen("sum.in", "r", stdin);
        //freopen("sum.out", "w", stdout);
        ios_base::sync_with_stdio(0);

        int n;
        cin >> n;
        vector < int > v;
        for(int i = 0; i < n; i++){
                int x;
                cin >> x;
                v.push_back(abs(x));
        }
        long long res = 0;

        sort(v.begin(), v.end());
        for(int i = 0, j = 0; i < v.size(); i++){
                while(v[j] * 2 < v[i]){
                        j += 1;
                }
                res += i - j;
        }

        cout << res << "\n";
}