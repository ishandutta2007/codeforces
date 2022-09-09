#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = -1;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        string s;
        cin >> s;
        if(not count(s.begin(), s.end(), '0') or not count(s.begin(), s.end(), '1')) cout << s << "\n";
        else{
            for(int i = 0; i < (int)s.size(); i += 1)
                cout << "10";
            cout << "\n";
        }
    }
    return 0;
}