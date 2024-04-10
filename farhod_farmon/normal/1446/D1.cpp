#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;
const int Q = 2 * N;

using namespace std;

int n;
int a[N];
int s[N];
int c[Q];

int solve(int x, int y)
{
        for(int i = 0; i < Q; i++){
                c[i] = n;
        }
        int res = 0;
        c[N] = 0;
        for(int i = 1; i <= n; i++){
                s[i] = s[i - 1];
                if(a[i] == x){
                        s[i] += 1;
                } else if(a[i] == y){
                        s[i] -= 1;
                }
                //cout << s[i] << " ";
                //s[i] + N;
                if(c[s[i] + N] == n){
                        c[s[i] + N] = i;
                } else{
                        res = max(res, i - c[s[i] + N]);
                }
        }
        return res;
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        cin >> n;
        vector < int > c(101, 0);
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                c[a[i]] += 1;
        }
        int mx = 0;
        for(int i = 0; i < 101; i++){
                if(c[i] > c[mx]){
                        mx = i;
                }
        }
        //cout << solve(1, 3) << endl;
        //return 0;
        int res = 0;
        for(int i = 1; i <= 100; i++){
                if(i == mx){
                        continue;
                }
                res = max(res, solve(mx, i));
        }
        cout << res << "\n";
}