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

void print0(){
    puts("Daenerys");
    exit(0);
}

void print1(){
    puts("Stannis");
    exit(0);
}

int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    int s0 = 0, s1 = 0;
    for (int i = 0; i < n; ++i){
        int x;
        scanf("%d", &x);
        if (x & 1) ++s1; else ++s0;
    }
    int total = 0;
    if (s1 & 1) total = 1;
    int tot = n - k;
    if (tot == 0){
        if ((tot & 1) ^ total) print1(); else print0();
    }
    if (tot & 1){
        if (tot / 2 >= s1) print0();
        if (tot / 2 < s0) print1();
        if (((tot - s0) & 1) ^ total) print1(); else print0();
    } else {
        if (tot / 2 < s0) print0();
        if (((tot - s0) & 1) ^ total) print1(); else print0();
    }
    return 0;
}