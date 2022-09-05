#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    scanf("%d", &n);
    vector<int> V;
    while (n--) {
        V.push_back(1);
        while (V.size() > 1 && V[V.size() - 2] == V.back()) {
            int x = V.back() + 1;
            V.pop_back(), V.pop_back(), V.push_back(x);
        }
    }
    for (int x : V) printf("%d ", x);
    return 0;
}