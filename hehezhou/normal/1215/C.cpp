#include <bits/stdc++.h>
using namespace std;
char s[200010], t[200010];
int n;
vector<int> posab, posba;
int main() {
    scanf("%d%s%s", &n, s + 1, t + 1);
    for(int i = 1; i <= n; i++) {
        if(s[i] == 'a' && t[i] == 'b') posab.push_back(i);
        if(s[i] == 'b' && t[i] == 'a') posba.push_back(i);
    }
    if((posab.size() + posba.size()) % 2) return puts("-1"), 0;
    printf("%d\n", (posab.size() + posba.size()) / 2 + posab.size() % 2);
    if(posab.size() % 2) {
        int d = posab.size() - 1;
        printf("%d %d\n", posab[d], posab[d]);
        posba.push_back(posab[d]);
        posab.pop_back();
    }
    for(int i = 0; i < posab.size(); i += 2) {
        printf("%d %d\n", posab[i], posab[i + 1]);
    }
    for(int i = 0; i < posba.size(); i += 2) {
        printf("%d %d\n", posba[i], posba[i + 1]);
    }
}