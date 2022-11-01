#include <bits/stdc++.h>

using namespace std;

char s[1000100];
string s1, s2;
vector<int> occ[27];
int ans = 1, pos = -1;

int main() {
    scanf("%s", s); s1 = s;
    scanf("%s", s); s2 = s;

    for(int i = 0; i < s1.size(); i++) {
        occ[s1[i]-'a'].push_back(i);
    }

    for(char c : s2) {
        int nxt = upper_bound(occ[c-'a'].begin(), occ[c-'a'].end(), pos) - occ[c-'a'].begin();

        if(nxt == occ[c-'a'].size()) {
            pos = -1;
            ans++;

            nxt = upper_bound(occ[c-'a'].begin(), occ[c-'a'].end(), pos) - occ[c-'a'].begin();
            if(nxt == occ[c-'a'].size()) {
                puts("-1");
                return 0;
            }
        }

        pos = occ[c-'a'][nxt];
    }

    printf("%d\n", ans);
    return 0;
}