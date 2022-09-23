#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 1000010;

using namespace std;

int n;
int t[N], r[N][2];
vector < int > v[N];
string s;

void upd(int x, int y)
{
        x = N - x - 2;
        while(x < N){
                t[x] = min(t[x], y);
                x += x & -x;
        }
}

int get(int x)
{
        x = N - x - 2;
        int res = n + 1;
        while(x > 0){
                res = min(res, t[x]);
                x -= x & -x;
        }
        return res;
}

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        cin >> n >> s;
        for(int i = 0; i < N; i++) t[i] = n + 1;
        for(int i = 0; i < n; i++){
                if(s[i] == '?'){
                        r[i][0] = r[i - 1][0] + 1;
                        r[i][1] = r[i - 1][1] + 1;
                } else if(s[i] == '0'){
                        r[i][0] = r[i - 1][0] + 1;
                } else{
                        r[i][1] = r[i - 1][1] + 1;
                }
                int R = max(r[i][0], r[i][1]);
                v[R].push_back(i + 1);
        }
        vector < int > R(n);
        for(int i = n; i >= 1; i--){
                for(int j: v[i]){
                        upd(j, j);
                }
                int cur = i, res = 0, g = get(cur);
                //cout << g << endl;
                //return 0;
                //if(i > 1) continue;
                while(g <= n){
                        //cout << cur << " " << g << endl;
                        res += 1;
                        cur = g + i;
                        g = get(cur);
                }
                R[i - 1] = res;
        }
        for(int x: R) printf("%d ", x);
}