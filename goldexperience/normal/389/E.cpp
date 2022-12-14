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

int c[10000];

int main(){
    int n;
    scanf("%d", &n);
    vector<int> vec;
    int l = 0, r = 0;
    for (int i = 0; i < n; ++i){
        int s;
        scanf("%d", &s);
        for (int j = 1; j <= s; ++j){
            scanf("%d", &c[j]);
            if (s % 2 == 1 && j == (s + 1) / 2) continue;
            if (j <= (s + 1) / 2) l += c[j]; else r += c[j];
        }
        if (s % 2) vec.push_back(c[(s + 1) / 2]);
    }
    sort(vec.begin(), vec.end());
    for (int i = sz(vec) - 1; i >= 0; --i)
        if ((sz(vec) - i) % 2) l += vec[i]; else r += vec[i];
    printf("%d %d\n", l, r);
    return 0;
}