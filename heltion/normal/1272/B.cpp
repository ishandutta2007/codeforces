#include<bits/stdc++.h>
using namespace std;
using LL = long long;
#define print(n, c) for(int i = 0; i < n; i += 1) cout << c;
int main(){
    int q;
    for(cin >> q; q; q -= 1){
        string s;
        cin >> s;
        int cnt[4] = {0, 0, 0, 0};
        for(char c : s)
            switch(c){
                case 'L' : cnt[0] += 1; break;
                case 'R' : cnt[1] += 1; break;
                case 'U' : cnt[2] += 1; break;
                case 'D' : cnt[3] += 1; break;
                default: break;
            }
        cnt[0] = cnt[1] = min(cnt[0], cnt[1]);
        cnt[2] = cnt[3] = min(cnt[2], cnt[3]);
        if(not cnt[0] and not cnt[2]) cout << "0\n\n";
        else if(not cnt[0]) cout << "2\nUD\n";
        else if(not cnt[2]) cout << "2\nLR\n";
        else{
            cout << (cnt[0] + cnt[2]) * 2 << "\n";
            print(cnt[1], 'R');
            print(cnt[2], 'U');
            print(cnt[0], 'L');
            print(cnt[3], 'D');
            cout << "\n";
        }
    }
}