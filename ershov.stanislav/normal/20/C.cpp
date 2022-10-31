#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

const long long inf=1000000000000000, nmax=100000;
int n, m, pr[nmax+1], sz=1;
long long wto[nmax+1];
vector<pair<int, long long> > v[nmax+1];
int ans[nmax];
pair<long long, int> heap[nmax*2+11];

inline int scani() {
    int x = 0, c = 0;
    while(c < 45) c = getchar();
    while(c >= 48 && c <= 57) {
        x = x*10 + c - 48;
        c = getchar();
    }
    return x;
}
inline void printi(int x) {
    int i = -1, num[10];
    while(x > 0) {
        num[++i] = x % 10 + 48;
        x /= 10;
    }
    while(i >= 0) putchar(num[i--]);
    putchar(' ');
}
inline void insertheap(pair<long long, int> n) {
    heap[sz]=n;
    int cur=sz++;
    while (heap[cur/2]>heap[cur]) swap(heap[cur/2], heap[cur]), cur=cur/2;
}
inline void popheap() {
    heap[1]=heap[--sz];
    int cur=1, ncur=0;
    while (cur*2<sz) {
        if (cur*2+1<sz&&heap[cur*2]>heap[cur*2+1]) ncur=cur*2+1;
        else ncur=cur*2;
        if (heap[cur]>heap[ncur]) swap(heap[cur], heap[ncur]), cur=ncur;
        else break;
    }
}

int main() {
    scanf("%d%d", &n, &m);
    int x=0, y=0, w=0;
    for (int i=1; i<=m; i++) {
        x=scani(), y=scani(), w=scani();
        v[x].push_back(make_pair(y, w));
        v[y].push_back(make_pair(x, w));
    }
    insertheap(make_pair(0, 1));
    for (int i=2; i<=n; i++) wto[i]=inf;
    wto[1]=0;
    while (sz>1) {
        int cur=heap[1].second;
        long long tocur=heap[1].first;
        popheap();
        if (wto[cur]!=tocur) continue;
        for (int i=0; i<v[cur].size(); i++) {
            int n=v[cur][i].first;
            if (wto[n]>wto[cur]+v[cur][i].second) {
                wto[n]=wto[cur]+v[cur][i].second;
                pr[n]=cur;
                insertheap(make_pair(wto[n], n));
            }
        }
    }
    if (wto[n]==inf) printf("-1");
    else {
        int j=0;
        for (int i=n; i!=0; i=pr[i], j++) ans[j]=i;
        for (int i=j-1; i>=0; i--) printi(ans[i]);
    }
    return 0;
}