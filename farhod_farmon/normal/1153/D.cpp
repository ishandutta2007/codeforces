#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 300300;

using namespace std;

int n;
int k;
int a[N];
vector < int > v[N];

int solve(int x)
{
        if(v[x].empty()){
                k += 1;
                return 1;
        }
        int res = 1e9 * a[x];
        for(int y: v[x]){
                if(a[x] == 0){
                        res += solve(y);
                } else{
                        res = min(res, solve(y));
                }
        }

        return res;
}


int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        for(int i = 2; i <= n; i++){
                int x;
                cin >> x;
                v[x].push_back(i);
        }

        int res = solve(1);
        cout << k - res + 1 << "\n";
}