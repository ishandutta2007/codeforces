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

    int n;
    cin >> n;
    vector<int> a;
    while (n){
        a.push_back(n % 10);
        n /= 10;
    }
    int m = *(max_element(all(a)));
    cout << m << "\n";
    for (int i = 0; i < m; i++){
        string ans = "";
        for (auto c : a){
            if (c > i)
                ans = "1" + ans;
            else
                ans = "0" + ans;
        }
        int pos = 0;
        while (ans[pos] == '0')
            pos++;
        ans = ans.substr(pos);
        cout << ans << " ";
    }
    cout << "\n";

    return 0;
}