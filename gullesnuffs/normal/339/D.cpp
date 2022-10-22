#include <stdio.h>
#include <cmath>
#include <algorithm>
#define OP_OR 0
#define OP_XOR 1

using namespace std;

int t[550000];

void update(int pos, bool type){
    if(!pos)
        return;
    if(type == OP_OR)
        t[pos]=t[pos*2]|t[pos*2+1];
    else
        t[pos]=t[pos*2]^t[pos*2+1];
    update(pos/2, 1-type);
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i=(1<<n); i < (1<<(n+1)); ++i){
        scanf("%d", t+i);
        update(i/2, OP_OR);
    }
    for(int i=0; i < m; ++i){
        int p, b;
        scanf("%d%d", &p, &b);
        t[(1<<n)+p-1]=b;
        update(((1<<n)+p-1)/2, OP_OR);
        printf("%d\n", t[1]);
    }
    return 0;
}