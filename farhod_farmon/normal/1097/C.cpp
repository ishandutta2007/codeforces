#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 500500;
const long long mod = 1e9 + 9;

using namespace std;

int n;
int a[N + N];
int b[N + N];
int c[N + N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        for(int i = 1; i <= n; i++){
                string s;
                cin >> s;
                int p = 0, f = 0;
                for(int j = 0; j < s.size(); j++){
                        if(s[j] == '('){
                                f += 1;
                        }
                        else{
                                f -= 1;
                        }
                        p = min(p, f);
                }
                int res = 0;
                if(p == 0){
                        res += 1;
                }
                if(p >= f){
                        res += 2;
                }
                if(res == 1){
                        a[f + N] += 1;
                }
                else if(res == 2){
                        b[f + N] += 1;
                }
                else if(res == 3){
                        c[f + N] += 1;
                }
        }
        int res = c[N] / 2;
        for(int i = 1; i < N; i++){
                int y = - i + N, x = i + N;
                int g = min(a[x], b[y]);
                a[x] -= g;
                b[y] -= g;
                res += g;
                g = min(b[x], a[y]);
                b[x] -= g;
                a[y] -= g;
                res += g;
                g = min(c[x], b[y]);
                res += g;
                c[x] -= g;
                b[y] -= g;
                g = min(c[y], b[x]);
                c[y] -= g;
                b[x] -= g;
                res += g;
                res += min(c[x], c[y]);
        }
        cout << res << "\n";
}