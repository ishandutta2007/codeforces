#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;


char a[111], b[111], ch;
string s;

int n, n1, n2;
int main(){
    while (1){
        scanf("%c", &ch);
        if (ch == '|') break;
        a[++n1] = ch;
    }
    while (1){
        scanf("%c", &ch);
        if (ch == '\n') break;
        b[++n2]=  ch;
    }
    cin >> s;
    int n = s.size();

    if (n < abs(n1 - n2) || (n > abs(n1 - n2) && (n - abs(n1 - n2)) % 2 == 1)) puts("Impossible");
    else{
        int t = abs(n1 - n2);
        if (n1 < n2){
            for (int i = 0; i < t; i++) a[++n1] = s[i];
            for (int i = t; i < n; i++){
                if (i & 1) a[++n1] = s[i];
                else b[++n2] = s[i];
            }
        }else{
            for (int i = 0; i < t; i++) b[++n2] = s[i];
            for (int i = t; i < n; i++){
                if (i & 1) a[++n1] = s[i];
                else b[++n2] = s[i];
            }
        }
        for (int i = 1; i <= n1; i++) printf("%c", a[i]);
        putchar('|');
        for (int i = 1; i <= n2; i++) printf("%c", b[i]);
    }
}