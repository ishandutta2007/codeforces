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

const int maxn = 200 * 1000 + 100;

int n;
int tnum;
char str[maxn];

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    scanf("%d", &tnum);
    for (int tc = 0; tc < tnum; tc++) {
        scanf("%d", &n);
        scanf("%s", str);

        int ans = 0;
        for (int i = 0; i < n / 2; i++) {
            ans += str[2 * i] != str[2 * i + 1];
        }
        printf("%d\n", ans);
    }

    return 0;
}