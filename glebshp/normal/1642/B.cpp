#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
 
using namespace std;
 
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int tc;
    scanf("%d", &tc);
    for (int tnum = 0; tnum < tc; tnum++) {
        int n;
        scanf("%d", &n);
        set <int> pups;
        for (int i = 0; i < n; i++) {
            int v;
            scanf("%d", &v);
            pups.insert(v);
        }

        for (int i = 1; i <= n; i++) {
            printf("%d ", max((int) pups.size(), i));
        }
        printf("\n");
    }

    return 0;
}