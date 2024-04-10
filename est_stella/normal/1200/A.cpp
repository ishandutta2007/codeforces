#include<bits/stdc++.h>
using namespace std;

set<int> S;
int n;
bool chk[11];

int main() {
    scanf("%d", &n);

    for(int i=0; i<10; i++)
        S.insert(i);

    scanf("\n");

    for(int i=0; i<n; i++) {
        char c;
        scanf("%c", &c);

        if(c == 'L') {
            set<int>::iterator it =  S.begin();
            chk[*it] = true;
            S.erase(it);
        }
        else if(c == 'R') {
            set<int>::iterator it =  S.end();
            it--;
            chk[*it] = true;
            S.erase(it);
        }
        else {
            chk[c - '0'] = false;
            S.insert(c-'0');
        }
    }

    for(int i=0; i<10; i++)
        printf("%d", chk[i]);
}