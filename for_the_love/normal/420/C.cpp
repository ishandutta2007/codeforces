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
const int N = 3e5 + 7;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;

struct Edge{
    int y, next;
} e[N + N];

int head[N],b[N], cnt[N], n, m, tot;



void Addedge(int x, int y){
    e[++tot].y = y; e[tot].next = head[x]; head[x] = tot;
    e[++tot].y = x; e[tot].next = head[y]; head[y] = tot;
}


inline int lowbit(int x){return x & -x;}

void Add(int x, int y){
    for (; x <= n + 1; x += lowbit(x)) b[x] += y;
}

int Q(int x){
    int ret = 0;
    for (; x; x -= lowbit(x)) ret += b[x];
    return ret;
}

int Query(int x){
    return Q(n + 1) - Q(x - 1);
}

int main(){
    int x, y;
    scanf("%d%d", &n, &m);
    tot = -1, memset(head, -1, sizeof(head));
    for (int i = 1; i <= n; i++){
        scanf("%d%d", &x, &y);
        cnt[x]++, cnt[y]++;
        Addedge(x, y);
    }

    for (int i = 1; i <= n; i++) Add(cnt[i] + 1, 1);

    LL ans = 0;


    for (int i = 1; i <= n; i++){
        for (int p = head[i]; p != -1; p = e[p].next){
            Add(cnt[e[p].y] + 1, -1);
            cnt[e[p].y] --;
            Add(cnt[e[p].y] + 1, 1);
        }
        ans += Query(max(1, m - cnt[i] + 1));
        if (cnt[i] + 1 >= max(1, m - cnt[i] + 1)) ans--;

        for (int p = head[i]; p != -1; p = e[p].next){
            Add(cnt[e[p].y] + 1, -1);
            cnt[e[p].y] ++;
            Add(cnt[e[p].y] + 1, 1);
        }
    }
    //cout << ans << endl;
    cout << ans / 2<< endl;

}