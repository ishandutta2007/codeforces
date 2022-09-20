#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200100;

using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int n;
        long long T;
        cin >> n >> T;
        string s;
        cin >> s;
        T += (1ll << s[n - 2] - 'a');
        T -= (1ll << s[n - 1] - 'a');
        vector < long long > c(26, 0);
        for(int i = 0; i < n - 2; i++){
                c[s[i] - 'a'] += 1;
        }
        for(long long i = 25; i >= 0; i--){
                if(T < 0){
                        T = - T;
                }

                long long X = (1ll << i);
                long long g = min(T / X, c[i]);
                T -= g * X;
                c[i] -= g;
                c[i] %= 2;
                if(c[i] == 1){
                        T -= X;
                }
        }

        cout << (T ? "No" : "Yes") << "\n";
}