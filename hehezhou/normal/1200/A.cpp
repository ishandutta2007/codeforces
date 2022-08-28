#include <bits/stdc++.h>
using namespace std;
int a[10];
char s[100010];
int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", s);
    for(int i = 0; i < n; i++) {
        if(s[i] == 'L') {
            for(int i = 0; i < 10; i++) if(a[i] == 0) {a[i] = 1; break;}
        }
        else if(s[i] == 'R') {
            for(int i = 9; i >= 0; i--) if(a[i] == 0) {a[i] = 1; break;}
        }
        else a[s[i] - '0'] = 0;
    }
    for(int i = 0; i < 10; i++) cout << a[i];
    return 0;
}