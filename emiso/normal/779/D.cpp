#include <bits/stdc++.h>

using namespace std;

string t, p;
int id[200200], rem[200200];

bool ok(int m) {
    int nxt = 0;

    for(int i=0; i<t.size();i++) {
        if(t[i] == p[nxt] && rem[i+1] > m) {
            nxt++;
            if(nxt == p.size()) return true;
        }
    }
    return false;
}

int main() {
    cin >> t >> p;
    for(int i=1;i<=t.size();i++) {
        scanf("%d", &id[i]);
        rem[id[i]] = i;
    }

    int l = 0, r = t.size() - 1, m;
    while(l < r) {
        m = (l + r + 1) / 2;
        if(ok(m))
            l = m;
        else
            r = m - 1;
    }

    printf("%d\n", l);

    return 0;
}