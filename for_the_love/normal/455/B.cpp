#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define PB push_back
#define MP make_pair

typedef long double DB;
typedef long long LL;
typedef pair<int, int> PI;

const DB eps = 1e-8;
const int N = 1e5 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
struct Trie{
    int next[26];
} t[N];

int cnt;

void Insert(char* s){
    int n = strlen(s), x = 1;
    for (int i = 0; i < n; i++){
        if (!t[x].next[s[i] - 'a']) t[x].next[s[i] - 'a'] = ++cnt;
        x = t[x].next[s[i] - 'a'];
    }
}

int Dfs(int x){
    int opt = 0;
    for (int i = 0; i < 26; i++)
    if (t[x].next[i]) opt |= 1 << Dfs(t[x].next[i]);
    if ((opt & 1) && (opt & 2)) return 2;
    if (opt == 4) return 3;
    if (opt & 8) return 2;
    if (opt & 1) return 1;
    return 0;
}

char s[N];

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    cnt = 1;
    for (int i = 1; i <= n; i++){
        scanf("%s", s);
        Insert(s);
    }
    int ans = Dfs(1);
    if (ans == 2) puts("First");
    else if (ans == 3) puts("Second");
    else if (ans == 1){
        if (m & 1) puts("First"); else puts("Second");
    }else puts("Second");
    //if ((ans + (m % 2)) % 2 ==  0) puts("First"); else puts("Second");
}