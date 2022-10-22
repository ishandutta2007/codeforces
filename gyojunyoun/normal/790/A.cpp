#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#define pb push_back
#define sz(V) ((int)(V).size())
#define allv(V) ((V).begin()),((V).end())
#define befv(V) ((V)[(sz(V)-2)])
#define upmin(ans,ansx) (ans)=min((ans),(ansx))
#define upmax(ans,ansx) (ans)=max((ans),(ansx))
#define INF (1100000099)
#define INFLL (1100000000000000099ll)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
inline void putString(const int& key) {
    putchar((key%26)+'A');
    if(26 <= key) putchar((key-26)+'a');
    putchar(' ');
}

int d[55];
int N, K, T;

int main() {
    scanf("%d%d", &N, &K);
    for(int i = 1; i < K; i++) d[i] = T++;
    for(int i = 1; i <= N-K+1; i++) {
        char str[5]; scanf(" %s", str);
        if(str[0] == 'N') d[i+K-1] = d[i];
        else d[i+K-1] = T++;
    }
    for(int i = 1; i <= N; i++) putString(d[i]);
    return 0;
}