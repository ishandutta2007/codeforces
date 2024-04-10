#include <cstdio>

const int MN = 1e5+10;
long long f[MN], b=0x3f3f3f3f3f3f3f3f;
int N, K, id;

int main()
{
    scanf("%d%d", &N, &K);
    for(int i=0,a;i<N;++i)
        scanf("%d", &a), f[i%K]+=a;
    for(int i=0;i<K;++i)
        if(f[i]<b)
            b=f[i], id=i;
    printf("%d\n", id+1);
    return 0;
}