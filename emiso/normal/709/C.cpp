#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cout << a << endl

using namespace std;

char shift(char a) {
    if(a == 'a') return 'z';
    else return a-1;
}

int main() {
    string s;
    cin >> s;

    string ans = s;

    int i=0;

    while(ans[i] == 'a' && i < s.size()) {
        i++;
    }

    if(i == s.size())
        ans[s.size()-1] = 'z';

    while(ans[i] != 'a' && i < s.size()) {
        ans[i] = shift(ans[i]);
        i++;
    }

    cout << ans;
    return 0;
}