#include <bits/stdc++.h>
using namespace std;

int k, ans[510];

int main() {
    scanf("%d", &k);
    ans[0] = 0;
    for (int i = 1; i <= 500; i++) {
        int j = i / 2;
        ans[i] = ans[j] + ans[i - j] + j * (i - j);
    }
    string s;
    if (!k) s = 'a';
    char c = 'a';
    for (int i = 500; ans[i]; i--) {
        while (k >= ans[i]) {
            s.append(string(i, c)), c++;
            k -= ans[i];
        }
    }
    printf("%s\n", s.c_str());
    return 0;
}