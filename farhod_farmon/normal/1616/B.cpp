#include "bits/stdc++.h"

#define fi first
#define se second

const int N = 100100;

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while(t--){
        int n;
        string s;
        cin >> n >> s;
        string res = "";
        res += s[0];
        for(int i = 1; i < n; i++){
            if(s[i] > res.back()){
                break;
            } else if(s[i] == res.back() && i == 1){
                break;
            }
            res += s[i];
        }
        auto t = res;
        reverse(t.begin(), t.end());
        res += t;
        cout << res << "\n";
    }
}