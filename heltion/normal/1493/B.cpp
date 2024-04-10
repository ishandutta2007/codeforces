#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setfill('0');
    int t;
    for(cin >> t; t; t -= 1){
        int h, m;
        cin >> h >> m;
        string s;
        cin >> s;
        int ch = stoi(s.substr(0, 2)), cm = stoi(s.substr(3));
        auto check = [&](int n){
            auto s = to_string(n);
            for(auto c : s) if(c == '3' or c == '4' or c == '6' or c == '7' or c == '9') return false;
            return true;
        };
        auto rev = [&](int n){
            auto s = to_string(n);
            if(s.size() == 1) s = '0' + s;
            reverse(s.begin(), s.end());
            for(char& c : s){
                if(c == '2') c = '5';
                else if(c == '5') c = '2';
            }
            return stoi(s);
        };
        while(not check(ch) or not check(cm) or rev(ch) >= m or rev(cm) >= h){
            cm += 1;
            if(cm == m){
                cm = 0;
                ch += 1;
            }
            if(ch == h) ch = 0;
        }
        cout << setw(2) << ch << ":" << setw(2) << cm << "\n";
    }
    return 0;
}