#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef long long ll;
typedef pair<ll, int> lli;

const int SIZE = 200005;
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;

vector<ii> graph[SIZE];
ll dist[SIZE];
int anterior[SIZE];
int proximo[SIZE];

void printAnterior(int n) {
    if(n == 1) {
        printf("1 ");
        return;
    }
    printAnterior(anterior[n]);
    printf("%d ", n);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    while(m--) {
        int a, b, w;
        scanf("%d %d %d", &a, &b, &w);
        graph[a].push_back(make_pair(b, w));
        graph[b].push_back(make_pair(a, w));
    }
    memset(dist, 63, sizeof(dist));
    priority_queue<lli, vector<lli>, greater<lli> > q;
    dist[1] = 0;
    q.push(make_pair(0, 1));
    while(!q.empty()) {
        ii v = q.top();
        q.pop();
        if(dist[v.second] < v.first) {
            continue;
        }
        for(ii a : graph[v.second]) {
            if(dist[v.second] + a.second < dist[a.first]) {
                dist[a.first] = dist[v.second] + a.second;
                anterior[a.first] = v.second;
                q.push(make_pair(dist[a.first], a.first));
            }
        }
    }
    if(dist[n] == INFLL) {
        printf("-1\n");
    } else {
        int a = n;
        while(a != 1) {
            proximo[anterior[a]] = a;
            a = anterior[a];
        }
        while(a != n) {
            printf("%d ", a);
            a = proximo[a];
        }
        printf("%d\n", a);
    }
    return 0;
}