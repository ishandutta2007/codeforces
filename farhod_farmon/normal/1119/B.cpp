#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 30030;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int h;
int a[N];

bool can(int m)
{
        vector < int > v;
        for(int i = 1; i <= m; i++){
                v.push_back(a[i]);
        }
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());

        int k = h;
        for(int i = 0; i < m; i += 2){
                int x = v[i];
                if(i + 1 < m){
                        x = max(x, v[i + 1]);
                }
                if(x > k){
                        return false;
                }
                k -= x;
        }
        return true;
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> h;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }

        int l = 1, r = n;
        while(l < r){
                int m = (l + r) / 2;
                if(can(m + 1)){
                        l = m + 1;
                } else{
                        r = m;
                }
        }

        cout << l << "\n";
}