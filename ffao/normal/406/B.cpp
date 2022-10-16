#include <stdio.h>
#include <set>
#include <vector>

using namespace std;

int n, a;
set<int> s;
vector<int> ans;
vector<int> fr;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        s.insert(a-1);
    }

    int cnt = 0;
    for (int i = 0; i <= 499999; i++) {
        bool is_sm = s.count(i);
        bool is_big = s.count(1000000-i-1);
        if (is_sm && is_big) cnt++;
        else if (is_sm) ans.push_back(1000000-i-1);
        else if (is_big) ans.push_back(i);
        else fr.push_back(i);
    }

    for (int i = 0; i < cnt; i++) {
        ans.push_back(fr[i]);
        ans.push_back(1000000-fr[i]-1);
    }

    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); i++) {
        printf("%d ", ans[i]+1);
    }
}