#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <bitset>

typedef long long LL;
#define pb push_back
#define MPII make_pair<int, int>
#define PII pair<int, int>
#define sz(x) (int)x.size()

using namespace std;

template<class T> T abs(T x){if (x < 0) return -x; else return x;}

int main(){
    int n;
    scanf("%d", &n);
    if (n < 4){
        puts("NO");
        return 0;
    }
    puts("YES");
    while (n > 5){
        printf("%d - %d = 1\n", n, n - 1);
        printf("%d * %d = %d\n", 1, n - 2, n - 2);
        n -= 2;
    }
    if (n == 5){
        puts("3 * 5 = 15");
        puts("2 * 4 = 8");
        puts("15 + 8 = 23");
        puts("23 + 1 = 24");
    } else {
        puts("1 * 2 = 2");
        puts("2 * 3 = 6");
        puts("6 * 4 = 24");
    }
    return 0;
}