#include <stdio.h>
#include <algorithm>

#define INF -1000000000000000LL

using namespace std;
typedef long long ll;

ll N,arr[100100],M,Q;

struct tree{
    ll left,right,total,best;
}n[400400];

inline int gm(ll a, ll b) {
    return a+(b-a)/2;
}

tree merrge(tree a, tree b) {
    tree n;
    n.left = max(b.left, b.total + a.left);
    n.left = max(n.left, INF);

    n.right = max(a.right,a.total + b.right);
    n.right = max(n.right, INF);

    n.total = a.total + b.total;
    n.total = max(n.total, INF);

    n.best = max(max(a.best,b.best),a.left + b.right);
    n.best = max(n.best, INF);
    return n;
}

void build(int node,int a,int b) {
    if(a==b) {
        n[node].total = n[node].best = n[node].left = n[node].right = arr[a];
        return;
    }

    build(node*2,a,gm(a,b));
    build(node*2+1,gm(a,b)+1,b);

    n[node] = merrge(n[node*2],n[node*2+1]);
}

tree query(int node,int a,int b,int x,int y) {
    if(x<=a && y>=b) return n[node];
    if(gm(a,b)<x) return query(node*2+1,gm(a,b)+1,b,x,y);
    if(gm(a,b)+1>y) return query(node*2,a,gm(a,b),x,y);
    return merrge(query(node*2,a,gm(a,b),x,y),query(node*2+1,gm(a,b)+1,b,x,y));
}

void update(int node, int a, int b, int x, ll y) {
    if(x > b || x < a) return;

    if(a == b) {
        n[node].total = n[node].best = n[node].left = n[node].right = y;
        return;
    }

    int mid = a + (b-a)/2;
    update(node*2,a,mid,x,y);
    update(node*2+1,mid+1,b,x,y);

    n[node] = merrge(n[node*2],n[node*2+1]);
}

int main() {
    int x,y,q;
    scanf("%d",&N);

    for(int i=1;i<=N;i++) {
        scanf("%lld",&arr[i]);
    }
    build(1,1,N);

    for(int i=0;i<N;i++) {
        scanf("%d",&x);
        update(1,1,N,x, INF);

        ll q = max(0LL,query(1,1,N,1,N).best);
        printf("%lld\n",q);
    }
    return 0;
}