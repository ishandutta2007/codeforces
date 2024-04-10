// Codeforces Beta Round #41
// Problem D -- Strange town
#include <cstdio>
#include <cstring>
#include <set>
#include <algorithm>

using namespace std;

const int N = 22;

int a[N];
set <int> hash;

int main () {
    a[0] = 0;
    hash.clear();
    for (int i = 1; i < N; ++ i) {
        a[i] = a[i - 1];
        bool flag = false;
        while (!flag) {
            a[i] ++;
            flag = true;
            for (int k = 0; k < i && flag; ++ k) {
                if (hash.count(a[i] + a[k])) {
                    flag = false;
                }
            }
        }
        for (int k = 0; k < i; ++ k) {
            hash.insert(a[i] + a[k]);
        }
    }
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < n; ++ j) {
            printf("%d%c", i == j? 0: a[i] + a[j], j == n - 1? '\n': ' ');
        }
    }
    return 0;
}