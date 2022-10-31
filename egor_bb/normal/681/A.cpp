#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, flag = 0;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        string s;
        int a, b;
        cin >> s >> a >> b;
        if (a >= 2400 && b > a)
            flag = 1;
    }
    if (flag)
        puts("YES");
    else
        puts("NO");
}