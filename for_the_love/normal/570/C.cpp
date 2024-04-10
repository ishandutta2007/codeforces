#include <map>
#include <cmath>
#include <ctime>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

#define PB push_back
#define MP make_pair

typedef double DB;
typedef long long LL;
typedef pair<int, int> PI;

const DB eps = 1e-8;
const int N = 3e5 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;

int a[N], b[N];
char s[N];

int n, m;

inline int lowbit(int x){return x & -x;}

void Add(int x, int y){
    for (; x <= n; x += lowbit(x))
        b[x] += y;
}


int Query(int x){
    int ret = 0;
    for (; x; x -= lowbit(x))
        ret += b[x];
    return ret;
}
int main(){
    scanf("%d%d", &n, &m);
    scanf("%s", s + 1);
    a[n] = 0;
    for (int i = 1; i < n; i++){
        if (s[i] == '.' && s[i + 1] == '.') a[i] = 1;
        else a[i] = 0;
        Add(i, a[i]);
    }

    while (m--){
        int pos; char ch;
        scanf("%d %c", &pos, &ch);
        s[pos] = ch;

        for (int i = max(1, pos - 1); i <= min(pos + 1, n); i++){
            int t;
            if (i + 1 <= n && s[i] == '.' && s[i + 1] == '.'){
                t = 1;
            } else t = 0;
            Add(i, t - a[i]);
            a[i] = t;
        }
        printf("%d\n", Query(n));
    }

}