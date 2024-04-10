#include <bits/stdc++.h>

using namespace std;

string str;
int L, R, D, U, LR, DU;

int main() {
    cin >> str;

    for(int i=0; i< (int)str.size(); i++) {
        if(str[i] == 'L')
            L++, LR--;

        if(str[i] == 'R')
            R++, LR++;

        if(str[i] == 'U')
        U++, DU++;

        if(str[i] == 'D')
        D++, DU--;
    }

    if(str.size() % 2 == 1) printf("-1\n");
    else {
        int ans = 9999999;
        ans = abs(U - D)/2 + abs(L - R)/2 + abs(U - D)%2;

        printf("%d\n",ans);
    }
    return 0;
}