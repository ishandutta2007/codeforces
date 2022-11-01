#include <bits/stdc++.h>

using namespace std;

int n;

bool query(int R1, int C1, int R2, int C2) {
    printf("? %d %d %d %d\n", R1, C1, R2, C2);
    fflush(stdout);
    char ans[5];
    scanf("%s", ans);
    return ans[0] == 'Y';
}

int main() {
    scanf("%d", &n);
    string st, ed;

    int x = 1, y = 1;
    for(int i = 1; i < n; i++) {
        if(query(x+1, y, n, n)) x++, st += 'D';
        else y++, st += 'R';
    }

    x = n, y = n;
    for(int i = 1; i < n; i++) {
        if(query(1, 1, x, y-1)) y--, ed += 'R';
        else x--, ed += 'D';
    }
    reverse(ed.begin(), ed.end());

    printf("! %s%s\n", st.c_str(), ed.c_str());
    return 0;
}