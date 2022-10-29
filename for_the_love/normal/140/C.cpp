#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
struct Qnode{
    int a, b;
    friend bool operator <(Qnode a, Qnode b){
        return a.b < b.b;
    }
} q[3], p[100005];


bool cmp(Qnode a, Qnode b){return a.b > b.b;}
int b[3], cnt, n, num, ans[100005][3];


void calc(){
    for (int i = 0; i < 3; i++){
        b[i] = q[i].a;
        q[i].b--;
    }
    sort(b, b + 3);
    for (int i = 2; i >= 0; i--) ans[num][i] = b[2 - i];
    num++;
    sort(q, q + 3, cmp);
    while (cnt > 0 && !q[cnt - 1].b) cnt--;
}


priority_queue <Qnode> Q;
map <int, int> S;
int main(){
    scanf("%d", &n);
    int m = 0, t;
    for (int i = 1; i <= n; i++){
        scanf("%d", &t);
        if (!S[t]){
            S[t] = ++m;
            p[m].a = t;
            p[m].b = 1;
        }else p[S[t]].b++;
    }
    for (int i = 1; i <= m; i++) Q.push(p[i]);
    cnt = 0;
    while (!Q.empty()){
        Qnode now = Q.top(); Q.pop();
        int found = 0;
        for (int k = 0; k < cnt; k++)
        if (now.a == q[k].a){
            found = 1;
            q[k].b++;
            break;
        }
        if (!found){
            q[cnt].a = now.a;
            q[cnt++].b = 1;
        }
        if (cnt == 3) calc();
        now.b--;
        if (now.b) Q.push(now);
    }

    printf("%d\n", num);
    for (int i = 0; i < num; i++)
        printf("%d %d %d\n", ans[i][0], ans[i][1], ans[i][2]);
}