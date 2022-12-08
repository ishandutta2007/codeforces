#include <iostream>
#include <cstdio>

#include <string>

using namespace std;

const int MAXN = 202000;
const int MAXM = 202000;
const char WILD = '*';

int N, M;
string s, t;

int main() {
    cin >> N >> M;
    cin >> s >> t;
    
    int pre = 0, suf = 0;
    
    bool ans = true;
    
    for(int i = 0;true;i++) {
        if(s[i] == WILD) break;
        if(i >= M or i >= N) {ans = (ans and (not (i >= M xor i >= N))); break;}
        if(s[i] == t[i]) pre++;
        else ans = false;
    }
    for(int i = N-1, j = M-1;true;i--, j--) {
        if(s[i] == WILD) break;
        if(j < 0 or i < 0) {ans = (ans and (not (j < 0 xor i < 0))); break;}
        if(s[i] == t[j]) suf++;
        else ans = false;
    }
    if(N - 1 > M) ans = false;
    
    if(ans) printf("YES\n");
    else printf("NO\n");
    
    return 0;
}