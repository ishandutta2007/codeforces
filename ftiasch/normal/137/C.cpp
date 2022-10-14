#include <cstdio>
#include <cstring>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector <pair <int, int> > v;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i) {
        int a, b;
        scanf("%d%d", &a, &b);
        v.push_back(make_pair(a, b));
    }
    sort(v.begin(), v.end());
    int result = 0;
    int rightMax = 0;
    for (vector <pair <int, int> > :: iterator iter = v.begin();
            iter != v.end(); ++ iter) {
        if (rightMax > iter->second) {
            result ++;
        }
        rightMax = max(rightMax, iter->second);
    }
    printf("%d\n", result);
    return 0;
}