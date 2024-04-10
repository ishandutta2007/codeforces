#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 400400;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int d[N];
set < int > s;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        int l = 1, r = n;
        for(int i = 2; i <= n; i++){
                int x;
                cin >> x;
                d[i] = d[i - 1] + x;
                if(s.find(d[i]) == s.end() && d[i] != 0){
                        s.insert(d[i]);
                } else{
                        cout << -1 << "\n";
                        return 0;
                }
                l = max(l, 1 - d[i]);
                r = min(r, n - d[i]);
        }
        if(l != r){
                cout << -1 << "\n";
                return 0;
        }
        for(int i = 1; i <= n; i++){
                cout << l + d[i] << " ";
        }
}