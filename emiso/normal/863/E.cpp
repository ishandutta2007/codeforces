#include <bits/stdc++.h>
#define MN 200200

using namespace std;
typedef long long ll;

int arr[1200100], tree[4800100];
const int inf=1111111111;

int gmid(int a,int b) {
    return a+(b-a)/2;
}

int min(int a,int b) {return a<b?a:b;}

void build(int node, int a, int b) {
    if(a==b) {
        tree[node] = arr[a];
        return;
    }
    build(node*2,a,gmid(a,b));
    build(node*2+1,gmid(a,b)+1,b);
    tree[node] = min(tree[node*2],tree[node*2+1]);
}

int query(int node, int a, int b, int x, int y) {
    if(x > b || y < a) return inf;
    if(x<=a && y>=b) return tree[node];
    return min(query(node*2,a,gmid(a,b),x,y),
                query(node*2+1,gmid(a,b)+1,b,x,y));
}

int n, l[MN], r[MN];
vector<int> y;

int main() {
    scanf("%d", &n);

    for(int i=1; i<=n; i++) {
        scanf("%d %d", &l[i], &r[i]);
        y.push_back(l[i]);
        y.push_back(r[i]);

        y.push_back(l[i] - 1);
        y.push_back(l[i] + 1);
        y.push_back(r[i] - 1);
        y.push_back(r[i] + 1);
    }

    sort(y.begin(),y.end());
    y.resize(unique(y.begin(),y.end()) - y.begin());

    int maxi = 0;
    for(int i=1;i<=n;i++) {
        l[i] = lower_bound(y.begin(), y.end(), l[i]) - y.begin() + 1;
        r[i] = lower_bound(y.begin(), y.end(), r[i]) - y.begin() + 1;
        //printf(" - %d %d\n", l[i], r[i]);
        arr[l[i]]++;
        arr[r[i]+1]--;

        maxi = max(maxi, r[i] + 1);
    }

    for(int i = 1; i <= maxi; i++) {
        arr[i] += arr[i-1];
    }

    build(1, 1, maxi);
    for(int i=1; i<=n; i++) {
        int qr = query(1, 1, maxi, l[i], r[i]);
        assert(qr > 0 && qr < inf);
        if(qr > 1) {
            printf("%d\n", i);
            return 0;
        }
    }

    printf("-1\n");
    return 0;
}