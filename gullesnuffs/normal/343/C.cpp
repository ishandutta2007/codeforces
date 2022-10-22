#include <cstdio>
#include <cmath>

using namespace std;

int n, m;
long long h[1000005], p[1000005];

long long Abs(long long x){
    return x>0?x:-x;
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i=0; i < n; ++i)
        scanf("%I64d", h+i);
    for(int i=0; i < m; ++i)
        scanf("%I64d", p+i);
    long long Min=-1, Max=10000000000005LL;
    while(Max-Min > 1LL){
        long long test=(Max+Min)/2;
        int last=0;
        bool ok=1;
        for(int i=0; i < n; ++i){
            if(h[i]-p[last] > test){
                ok=0;
                break;
            }
            int j;
            for(j=last; j < m; ++j){
                if(Abs(p[j]-h[i])+p[j]-p[last] <= test)
                    continue;
                if(Abs(h[i]-p[last])+p[j]-p[last] <= test)
                    continue;
                break;
            }
            last=j;
            if(last == m)
                break;
        }
        if(!ok || last < m)
            Min=test;
        else
            Max=test;
    }
    printf("%I64d\n", Max);
    return 0;
}