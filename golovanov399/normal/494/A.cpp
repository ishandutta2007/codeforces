#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

using namespace std;

int main(){

    string s;
    cin >> s;
    int k = 0;
    int mn = 0;
    vector<int> ans;
    for (auto c : s){
        if (c == '#'){
            mn = k;
            if (k > 0){
                ans.pb(1);
                k--;
            } else {
                cout << "-1\n";
                return 0;
            }
        } else
        if (c == '('){
            k++;
        } else {
            if (k > 0) {
                k--;
            } else {
                cout << -1 << "\n";
                return 0;
            }
        }
        mn = min(mn, k);
    }
    if (k > mn){
        cout << "-1\n";
        return 0;
    }
    ans.back() += k;
    for (auto x: ans)
        cout << x << "\n";

    return 0;
}