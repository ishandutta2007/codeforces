#include <bits/stdc++.h>
using namespace std;
           
#define ll longl long
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db long double

int n;
string s[500007];

map<int, int> was;

int main(){
   // freopen("input.txt", "r", stdin);
    //freopen("output1.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int i = 0; i < n; i++){
        int ok = 1;
        int bal = 0;
        for (int j = 0; j < s[i].size(); j++){
            if (s[i][j] == '('){
                bal++;
            } else {
                if (bal == 0){
                    ok = 0;
                    break;
                }
                bal--;
            }
        }
        if (ok) was[bal]++;
        ok = 1;
        bal = 0;
        for (int j = (int)s[i].size() - 1; j >= 0; j--){
            if (s[i][j] == '('){
                if (bal == 0){
                    ok = 0;
                    break;
                }
                bal++;
            } else {
                bal--;
            }
        }
        if (ok) was[bal]++;
    }
    int ans = 0;
    for (auto c : was){
        if (c.x > 0){
            ans += min(was[c.x], was[-c.x]);
        } else if (c.x == 0){
            ans += (c.y / 2) / 2;
        }
    }
    cout << ans;
}