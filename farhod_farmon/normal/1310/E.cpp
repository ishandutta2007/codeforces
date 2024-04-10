#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")

#define fi first
#define se second

const int N = 2024;
const int mod = 998244353;

using namespace std;

int n;
int k;
int d[N][N];
int s[N][N];

void add(int &x, int y)
{
        x += y;
        if(x >= mod){
                x -= mod;
        }
}

int res;
vector < int > v;

bool good()
{
        vector < int > A = v, B;
        for(int i = 1; i <= k - 2; i++){
                B.clear();
                for(int j = 0; j < A.size(); j++){
                        for(int h = 0; h < A[j]; h++){
                                B.push_back(j + 1);
                        }
                }
                reverse(B.begin(), B.end());
                int sum = 0;
                for(int i = 0; i < B.size(); i++){
                        sum += B[i] * (i + 1);
                }
                if(sum > n){
                        return false;
                }
                A = B;
        }
        return true;
}

void rec(int mx)
{
        if(!v.empty()){
                if(good()){
                        res += 1;
                } else{
                        return;
                }
        }
        for(int i = mx; i > 0; i--){
                v.push_back(i);
                rec(i);
                v.pop_back();
        }
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(0);

        cin >> n >> k;
        for(int i = 0; i <= n; i++){
                s[i][0] = 1;
        }
        if(k == 1){
                for(int i = 1; i <= n; i++){
                        for(int j = 0; j <= n; j++){
                                for(int h = (i - 1) * j; h + j <= n; h++){
                                        add(d[j][h + j], s[j][h]);
                                }
                        }
                        if(i < n){
                                for(int j = n; j >= 0; j--){
                                        for(int h = (i - 1) * j; h <= n; h++){
                                                s[j][h] = d[j][h];
                                                add(s[j][h], s[j + 1][h]);
                                                d[j][h] = 0;
                                        }
                                }
                        }
                }
                int res = 0;
                for(int i = 0; i <= n; i++){
                        for(int j = 1; j <= n; j++){
                                add(res, d[i][j]);
                        }
                }
                cout << res << "\n";
                return 0;
        } else if(k == 2){
                for(int i = 1; i <= n; i++){
                        for(int j = 0; j <= n; j++){
                                for(int h = (i - 1) * j; h + j * i <= n; h++){
                                        add(d[j][h + j * i], s[j][h]);
                                }
                        }
                        if(i < n){
                                for(int j = n; j >= 0; j--){
                                        for(int h = (i - 1) * j; h <= n; h++){
                                                s[j][h] = d[j][h];
                                                add(s[j][h], s[j + 1][h]);
                                                d[j][h] = 0;
                                        }
                                }
                        }
                }
                int res = 0;
                for(int i = 0; i <= n; i++){
                        for(int j = 1; j <= n; j++){
                                add(res, d[i][j]);
                        }
                }
                cout << res << "\n";
                return 0;
        }

        rec(n);

        cout << res << "\n";
}