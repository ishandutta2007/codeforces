#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

map <int, int> S;
int n, i, t, cnt;
int main(){
    scanf("%d", &n);
    for (i = 1; i <= n; i++){
        scanf("%d", &t);
        S[t]++;
    }
    //sort(a + 1, a + n + 1);
    t = -1;
    while (1){
        if (S.upper_bound(t) == S.end()) break;
        t = (S.upper_bound(t)) -> first;
        if (S[t] / 2) S[t + 1] += S[t] / 2;
        S[t] = S[t] % 2;
        if (S[t]) cnt++;
    }
    printf("%d\n", t + 1 - cnt);
}