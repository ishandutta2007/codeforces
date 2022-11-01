#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

int n, k, a;
vector<int> ans;
set<int> ins;

int main() {
    scanf("%d %d", &n, &k);

    for(int i = 0; i < n; i++) {
        scanf("%d", &a);
        if(!ins.count(a)) {
            ans.push_back(i+1);
            ins.insert(a);
        }
    }

    if(ins.size() < k) printf("NO\n");
    else {
        printf("YES\n");
        for(int i = 0; i < k; i++) {
            printf("%d ", ans[i]);
        }
    }
    return 0;
}