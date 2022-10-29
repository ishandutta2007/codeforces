#include <map>
#include <set>
#include <cmath>
#include <queue >
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define PB push_back
#define MP make_pair

typedef double DB;
typedef long long LL;
typedef pair<LL, LL> PI;

const DB eps = 1e-8;
const int N = 1e5 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;

char S[N], str[N];

string s[N]; int t[N];
LL cnt[N], num[N];

int main(){
    int n;
    scanf("%s", S);
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%s", str);
        int l = strlen(str);
        t[i] = str[0] - '0';
        s[i] = "";
        for (int j = 3; j < l; j++) s[i] += str[j];
    }
    for (int i = 0; i < 10; i++) cnt[i] = 10, num[i] = i;
    //cout << s[0] << endl;
    for (int i = n - 1; i >= 0; i--){
        LL x = 0, y = 1;
        for (int j = (int)s[i].size() - 1; j >= 0; j--){
            x = (x + num[s[i][j] - '0'] * y) % MOD;
            y = (y * cnt[s[i][j] - '0']) % MOD;
        }
        num[t[i]] = x, cnt[t[i]] = y;
    }
    LL ans = 0, p = 1;
    for (int i = strlen(S) - 1; i >= 0; i--){
        ans = (ans + num[S[i] - '0'] * p) % MOD;
        p = (p * cnt[S[i] - '0']) % MOD;
    }
    printf("%d\n", (int)ans);
}