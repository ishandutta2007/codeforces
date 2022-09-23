#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;
const long long mod = 1e9 + 7;

using namespace std;

int c[N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int q;
        cin >> q;
        for(int i = 1; i <= q; i++){
                string s;
                cin >> s;
                for(int j = 'a'; j <= 'z'; j++){
                        c[j] = 0;
                }
                int res = 1;
                for(int x: s){
                        res &= !c[x];
                        c[x] = 1;
                }
                int cnt = 0;
                for(int j = 'a'; j <= 'z'; j++){
                        cnt += (!c[j - 1] && c[j]);
                }
                if(cnt == 1 && res == 1){
                        cout << "Yes" << "\n";
                } else{
                        cout << "No" << "\n";
                }
        }
}