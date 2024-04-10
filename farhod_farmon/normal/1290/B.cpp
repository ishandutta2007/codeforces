#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;
const int mod = 998244353;

using namespace std;

int n;
int q;
string a;
int s[N][26];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(0);

        cin >> a;
        n = a.size();
        for(int i = 1; i <= n; i++){
                for(int j = 0; j < 26; j++){
                        s[i][j] = s[i - 1][j];
                }
                s[i][a[i - 1] - 'a'] += 1;
        }
        cin >> q;
        for(int i = 1; i <= q; i++){
                int l, r;
                cin >> l >> r;
                int cnt = 0;
                for(int j = 0; j < 26; j++){
                        cnt += (s[r][j] - s[l - 1][j]) > 0;
                }
                if(cnt > 2 || l == r || a[l - 1] != a[r - 1]){
                        cout << "Yes" << "\n";
                } else{
                        cout << "No" << "\n";
                }
        }

}