#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    vector<int> already;
    auto add = [&](int a) {
        for(int b : already) {
            a = min(a, a ^ b);
        }
        if(a) {
            already.push_back(a);
        }
    };
    int pref = 0;
    for(int i = 0; i < n; ++i) {
        int nxt;
        scanf("%d", &nxt);
        pref ^= nxt;
        add(pref);
    }
    if(pref == 0) {
        puts("-1");
    }
    else {
        printf("%d\n", (int) already.size());
    }
}