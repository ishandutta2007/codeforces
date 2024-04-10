#include<bits/stdc++.h>
using namespace std;
using LL = long long;
bool ok[256];
int main(){
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    for(int i = 0; i < k; i += 1){
        string s;
        cin >> s;
        ok[s[0]] = 1;
    }
    LL ans = 0, cnt = 0;
    for(char c : s) if(ok[c]) cnt += 1;
    else{
        ans += cnt * (cnt + 1) / 2;
        cnt = 0;
    }
    ans += cnt * (cnt + 1) / 2;
    cout << ans;
}