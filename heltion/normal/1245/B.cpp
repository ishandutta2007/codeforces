#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n, a, b, c, m = 0;
        string s, t;
        cin >> n >> a >> b >> c >> s;
        for(int i = 0; i < n; i += 1){
            if(s[i] == 'R' and b){
                t.push_back('P');
                b -= 1;
                m += 1;
            }
            else if(s[i] == 'P' and c){
                t.push_back('S');
                c -= 1;
                m += 1;
            }
            else if(s[i] == 'S' and a){
                t.push_back('R');
                a -= 1;
                m += 1;
            }
            else t.push_back(0);
        }
        if(m < (n + 1) / 2) cout << "NO\n";
        else{
            cout << "YES\n";
            for(int i = 0; i < n; i += 1) if(not t[i]){
                if(a){
                    a -= 1;
                    t[i] = 'R';
                }
                else if(b){
                    b -= 1;
                    t[i] = 'P';
                }
                else if(c){
                    c -= 1;
                    t[i] = 'S';
                }
            }
            cout << t << "\n";
        }
    }
    return 0;
}