#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define PB push_back
#define MP make_pair

typedef double DB;
typedef long long LL;
typedef pair<int,int> PI;

const DB eps = 1e-6;
const int N = 5555;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;

char s[N], t[N];
int c[N];
int main(){
    scanf("%s%s", s + 1, t + 1);
    int n = strlen(s + 1), m = strlen(t + 1);
    int l = 1, f1 = 0, f2 = 0, f3 = 0;
    for (int i = 1; i <= m; i++){
        int flag = 0;
        for (int j = l; j <= n; j++)
        if (s[j] == t[i]){
            l = j + 1;
            flag = 1;
            break;
        }
        if (!flag) f1 = 1;
    }
    for (int i = 1; i <= n; i++) c[s[i] - 'a']++;
    for (int i = 1; i <= m; i++) c[t[i] - 'a']--;
    for (int i = 0; i < 26; i++) if (c[i] != 0) f2 = 1;
    if (!f1) {puts("automaton"); return 0;}
    if (!f2) {puts("array"); return 0;}
    for (int i = 1; i <= m; i++)
    if (c[t[i] - 'a'] < 0) f3 = 1;
    if (!f3) puts("both"); else puts("need tree");
}