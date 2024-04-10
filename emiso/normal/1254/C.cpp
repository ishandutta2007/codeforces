#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

int sgn(int i, int j, int k) {
    printf("2 %d %d %d\n", i, j, k); fflush(stdout);
    int x;
    scanf("%d", &x);
    return x;
}

ll area(int i, int j, int k) {
    printf("1 %d %d %d\n", i, j, k); fflush(stdout);
    ll x;
    scanf("%lld", &x);
    return x;
}

ll n;
pair<ll, int> dist[1010];
vector<int> ord, desc;

int main() {
    scanf("%lld", &n);

    ord.push_back(1);
    ll gr = 2;
    for(int i = 3; i <= n; i++)
        if(sgn(1, gr, i) < 0) gr = i;

    ord.push_back(gr);
    for(int i = 2; i <= n; i++) {
        if(i != gr) dist[i] = {area(1, gr, i), i};
        else dist[i] = {-1, i};
    }
    dist[1]= {-1, 1};

    sort(dist + 1, dist + n + 1);
    gr = dist[n].second;

    for(int i = 3; i < n; i++) {
        if(sgn(1, dist[i].second, gr) > 0) ord.push_back(dist[i].second);
        else desc.push_back(dist[i].second);
    }
    desc.push_back(dist[n].second);

    reverse(desc.begin(), desc.end());
    printf("0");
    for(int x : ord)  printf(" %d", x);
    for(int x : desc) printf(" %d", x);
    puts("");

    fflush(stdout);
    return 0;
}