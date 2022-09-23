#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;

using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        char m[200];

        m['S'] = 'R';
        m['R'] = 'P';
        m['P'] = 'S';

        int T;
        cin >> T;
        while(T--){
                // R P S
                int a, b, c, n;
                cin >> n >> a >> b >> c;
                string s;
                cin >> s;

                int cnt = 0;
                for(int i = 0; i < n; i++){
                        char cc = m[s[i]];
                        s[i] = 0;
                        if(cc == 'R' && a > 0){
                                cnt += 1;
                                a -= 1;
                                s[i] = cc;
                        }
                        if(cc == 'P' && b > 0){
                                cnt += 1;
                                b -= 1;
                                s[i] = cc;
                        }
                        if(cc == 'S' && c > 0){
                                cnt += 1;
                                c -= 1;
                                s[i] = cc;
                        }
                }
                if(cnt < (n + 1) / 2){
                        cout << "NO" << "\n";
                        continue;
                }
                cout << "YES" << "\n";
                for(int i = 0; i < n; i++){
                        if(s[i] == 0){
                                if(a > 0){
                                        s[i] = 'R';
                                        a -= 1;
                                } else if(b > 0){
                                        s[i] = 'P';
                                        b -= 1;
                                } else{
                                        s[i] = 'S';
                                }
                        }
                        cout << s[i];
                }
                cout << "\n";
        }
}