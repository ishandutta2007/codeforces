#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

int n,ans,last;

struct entry {
    int x,w;
} e[200005];

int comp(entry a, entry b) {
    return a.x + a.w == b.x + b.w ? a.x < b.x : a.x + a.w < b.x + b.w;
}

int main()
{
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d",&e[i].x,&e[i].w);
    }
    sort(e,e+n,comp);
    for (int i = 1; i < n; ++i) {
        if (e[i].x - e[i].w >= e[last].x + e[last].w) last = i, ++ans;
    }
    cout << ans+1;

    return 0;
}