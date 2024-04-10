// Codeforces Beta Round #87
// Problem E -- Linear Kingdom Races
#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 222222;

int n, m, c[N], l[N], r[N], p[N];
vector<int> events[N];
long long delta[N << 2], maximum[N << 2], dp[N];

void add(int t, int l, int r, int a, int b, long long c){
    if(b < l or r < a){
        return;
    }
    if(a <= l and r <= b){
        delta[t] += c;
        maximum[t] += c;
    }else{
        if(delta[t] != 0){
            delta[t + t] += delta[t];
            maximum[t + t] += delta[t];
            delta[t + t + 1] += delta[t];
            maximum[t + t + 1] += delta[t];
            delta[t] = 0;
        }
        int m = (l + r) >> 1;
        add(t + t, l, m, a, b, c);
        add(t + t + 1, m + 1, r, a, b, c);
        maximum[t] = max(maximum[t + t], maximum[t + t + 1]);
    }
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++ i){
        scanf("%d", c + i);
    }
    for(int i = 1; i <= m; ++ i){
        scanf("%d%d%d", l + i, r + i, p + i);
        events[r[i]].push_back(i);
    }
    memset(delta, 0, sizeof(delta));
    memset(maximum, 0, sizeof(maximum));
    long long result = 0;
    for(int i = 1; i <= n; ++ i){
        for(vector<int>::iterator iter = events[i].begin(); iter != events[i].end(); ++ iter){
            add(1, 0, n, 0, l[*iter] - 1, p[*iter]);
        }
        add(1, 0, n, 0, i - 1, -c[i]);           
        result = dp[i] = max(result, maximum[1]);
        add(1, 0, n, i, i, dp[i]);
    }
    cout << result << endl;
    return 0;
}