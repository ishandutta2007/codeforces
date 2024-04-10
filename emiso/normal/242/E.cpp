#include <stdio.h>

long long tree[400400][21],lazy[400400][21];
int ar[100100];

inline int gm(int a,int b) {
    return a + (b-a)/2;
}

void dolazy(int node,int a,int b,int j) {
    if(lazy[node][j] == 0) return;
    lazy[node][j] = 0;
    tree[node][j] = b - a + 1 - tree[node][j];
    if(a!=b) {
        lazy[node*2][j] ^= 1;
        lazy[node*2+1][j] ^= 1;
    }
}

void update(int node,int a,int b,int x,int y,int j) {
    dolazy(node,a,b,j);

    if(x > b || y < a) return;

    if(x <= a && b <= y) {

        tree[node][j] = ((long long)b-a+1) - tree[node][j];

        if(a!=b) {
            lazy[node*2][j] ^= 1;
            lazy[node*2+1][j] ^= 1;
        }

        return;
    }

    update(node*2,a,gm(a,b),x,y,j);
    update(node*2+1,gm(a,b)+1,b,x,y,j);

    tree[node][j] = tree[node*2][j] + tree[node*2+1][j];
}

long long query(int node,int a,int b,int x, int y,int j) {
    if(x > b || y < a) return 0;
    dolazy(node,a,b,j);
    if(x<=a && y>=b) return tree[node][j];
    return query(node*2,a,gm(a,b),x,y,j) +
            query(node*2+1,gm(a,b)+1,b,x,y,j);
}

int main() {
    int N,Q,l,r,x,t;
    scanf("%d",&N);

    for(int i=1;i<=N;i++) {
        scanf("%d",&ar[i]);
        for(int j=0;j<=20;j++)
            if(ar[i] & (1<<j)) update(1,1,N,i,i,j);
    }

    scanf("%d",&Q);

    for(int i=0;i<Q;i++) {
        scanf("%d",&t);

        if(t==1) {
            scanf("%d %d",&l,&r);
            long long sum = 0;
            for(int j=0;j<=20;j++) {
                sum += (long long)(1<<j)*(query(1,1,N,l,r,j));
            }
            printf("%I64d\n",sum);
        }

        else {
            scanf("%d %d %d",&l,&r,&x);
            for(int j=0;j<=20;j++) {
                if(x & (1<<j))
                    update(1,1,N,l,r,j);
            }
        }
    }
    return 0;
}