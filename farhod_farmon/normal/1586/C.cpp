#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 1000011;

using namespace std;

int n;
int m;
int s[N];
vector<vector<char>> a;

int main()
{
        #ifdef zxc
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif
        ios_base::sync_with_stdio(0);

        cin >> n >> m;
        a.resize(n);
        for(int i = 0; i < n; i++){
                a[i].resize(m);
                for(int j = 0; j < m; j++){
                        cin >> a[i][j];
                }
        }
        for(int i = 0; i + 1 < n; i++){
                for(int j = 1; j < m; j++){
                        if(a[i][j] == 'X' && a[i + 1][j - 1] == 'X'){
                                s[j] = 1;
                        }
                }
        }
        for(int i = 1; i < m; i++){
                s[i] += s[i - 1];
        }
        int q;
        cin >> q;
        for(int i = 0; i < q; i++){
                int l, r;
                cin >> l >> r;
                if(s[r - 1] - s[l - 1]){
                        cout << "NO\n";
                } else{
                        cout << "YES\n";
                }
        }
}