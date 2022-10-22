#include <stdio.h>
#include <algorithm>
#include <map>
#include <vector>
#include <stack>
#define MAXN 200000
#define MOD 1000000007

using namespace std;

int side, m;

struct Fenwick{
    long long a[1005][1005];
    long long b[1005][1005];
    long long c[1005][1005];
    long long d[1005][1005];

    Fenwick(){
        for(int i=0; i < 1005; ++i)
            for(int j=0; j < 1005; ++j)
                a[i][j]=0;
    }

    void update(int x, int y, long long u){
        for(int i=x; i < 1005; i |= i+1)
            for(int j=y; j < 1005; j |= j+1)
                if(!(x%2) && !(y%2))
                    a[i][j]^=u;
        for(int i=x; i < 1005; i |= i+1)
            for(int j=y-1; j >= 0; j=(j&(j+1))-1)
                if(!(x%2))
                    b[i][j]^=u;
        for(int i=x-1; i >= 0; i=(i&(i+1))-1)
            for(int j=y; j < 1005; j |= j+1)
                if(!(y%2))
                    c[i][j]^=u;
        for(int i=x-1; i >= 0; i=(i&(i+1))-1)
            for(int j=y-1; j >= 0; j=(j&(j+1))-1)
                d[i][j]^=u;
    }

    long long query(int x, int y){
        long long ret=0;
        for(int i=x; i >= 0; i=(i&(i+1))-1)
            for(int j=y; j >= 0; j=(j&(j+1))-1)
                ret^=a[i][j];
        for(int i=x; i >= 0; i=(i&(i+1))-1)
            for(int j=y; j < 1005; j |= j+1)
                if(!(y%2))
                    ret^=b[i][j];
        for(int i=x; i < 1005; i |= i+1)
            for(int j=y; j >= 0; j=(j&(j+1))-1)
                if(!(x%2))
                    ret^=c[i][j];
        for(int i=x; i < 1005; i |= i+1)
            for(int j=y; j < 1005; j |= j+1)
                if(!(x%2) && !(y%2))
                    ret^=d[i][j];
        return ret;
    }
}fenwick;

int main()
{
    scanf("%d%d", &side, &m);
    for(int i=0; i < m; ++i){
        int t;
        scanf("%d", &t);
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        --x1;
        --y1;
        if(t == 1){
            long long res=0;
            res ^= fenwick.query(x2, y2);
            res ^= fenwick.query(x1, y2);
            res ^= fenwick.query(x2, y1);
            res ^= fenwick.query(x1, y1);
            printf("%I64d\n", res);
        }else{
            int u;
            scanf("%I64d", &u);
            fenwick.update(x2, y2, u);
            fenwick.update(x1, y2, u);
            fenwick.update(x2, y1, u);
            fenwick.update(x1, y1, u);
        }
    }
    return 0;
}