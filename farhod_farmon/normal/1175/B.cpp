#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;
const int Q = 10000011;
const int mod = 1e9 + 7;

using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int n;
        long long res = 0, inf = (1ll << 32);
        vector < long long > v;
        v.push_back(1);
        cin >> n;
        for(int i = 1; i <= n; i++){
                string s;
                cin >> s;
                if(s[0] == 'f'){
                        long long x;
                        cin >> x;
                        v.push_back(v.back() * x);
                        v.back() = min(v.back(), inf);
                } else if(s[0] == 'e'){
                        v.pop_back();
                } else{
                        res += v.back();
                }
                if(res >= inf){
                        cout << "OVERFLOW!!!" << "\n";
                        return 0;
                }
        }
        cout << res << "\n";
}