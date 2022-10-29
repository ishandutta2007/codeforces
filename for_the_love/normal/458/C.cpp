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

typedef double DB;
typedef long long LL;
typedef pair<int, int> PI;

const DB eps = 1e-8;
const int N = 1e5 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;

struct Pnode{
    int x, y;
} p[N];

priority_queue<int, vector<int>, greater<int> > Hx;
priority_queue <int> Hd;

bool cmp(Pnode a, Pnode b){
    if (a.x == b.x) return a.y < b.y;
    return a.x > b.x;
}

vector <int> vec[N];
int s[N];


int main(){
    //freopen("in.txt", "r", stdin);
    int n, t = 0, x, y;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        scanf("%d%d", &x, &y);
        if (!x) t++; else vec[x].PB(y);
    }
    int m = 0;
    for (int i = 1; i <= 100000; i++){
        sort(vec[i].begin(), vec[i].end());
        for (int j = 0; j < vec[i].size(); j++){
            p[++m].x = vec[i].size() - j;
            p[m].y = vec[i][j];
        }
    }
    sort(p + 1, p + m + 1, cmp);
    for (int i = 1; i <= m; i++) s[i] = s[i - 1] + p[i].y;
    p[m + 1].x = 0;
    int ans = INF, sum = 0;
    for (int i = m; i >= 0; i--){
        while (!Hd.empty() && i + t - 1 > p[i + 1].x){
            int x = Hd.top(); Hd.pop();
            Hx.push(x);
            sum -= x;
            t--;
        }
        while (!Hx.empty() && i + t <= p[i + 1].x){
            int x = Hx.top(); Hx.pop();
            Hd.push(x);
            sum += x;
            t++;
        }
        while (!Hx.empty() && !Hd.empty()){
            int x = Hx.top(), y = Hd.top();
            if (y > x){
                Hx.pop(); Hd.pop();
                Hx.push(y); Hd.push(x);
            }else break;
        }
        if (i + t > p[i + 1].x) ans = min(ans, sum + s[i]);
        Hx.push(p[i].y);
    }
    printf("%d\n", ans);
}