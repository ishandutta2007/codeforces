#include <bits/stdc++.h>
#define MN 200500

using namespace std;

int n, a[MN], b[MN], ans[MN];
vector<pair<int, int> > vec;

int main() {
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &a[i]);
    } sort(a, a + n, greater<int>());

    for(int i=0; i<n; i++) {
        scanf("%d", &b[i]);
        vec.push_back({b[i], i});
    } sort(vec.begin(), vec.end());

    for(int i=0; i<n; i++) {
        ans[vec[i].second] = a[i];
    }

    for(int i=0; i<n; i++) {
        printf("%d ", ans[i]);
    }
    return 0;
}