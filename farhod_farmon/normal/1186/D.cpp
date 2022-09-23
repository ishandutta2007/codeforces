#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;
const long long mod = 998244353;

using namespace std;

int n;
int a[N];
int df[N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        long long S = 0;
        for(int i = 1; i <= n; i++){
                string s;
                cin >> s;
                int j;
                for(j = (s[0] == '-'); s[j] != '.'; j++){
                        a[i] = a[i] * 10 + s[j] - '0';
                }
                for(j = j + 1; j < s.size(); j++){
                        if(s[j] != '0'){
                                df[i] = 1;
                        }
                }
                if(s[0] == '-'){
                        a[i] = - a[i];
                        df[i] = - df[i];
                }
                S += a[i];
        }
        for(int i = 1; i <= n; i++){
                if(abs(S) > abs(S + df[i])){
                        S += df[i];
                        a[i] += df[i];
                }
                cout << a[i] << "\n";
        }
        assert(S == 0);
}