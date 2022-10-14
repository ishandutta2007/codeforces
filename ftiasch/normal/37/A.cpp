#include <cstdio>
#include <cstring>

using namespace std;

int n, l[1000], c[1001];

int main()
{
    scanf("%d", &n);
    memset(c, 0, sizeof(c));
    int max = 0, cnt = 0;
    for(int i = 0; i < n; ++ i)
    {
        scanf("%d", l + i);
        c[l[i]] ++;
        cnt += (c[l[i]] == 1);
        if(c[l[i]] > max)
            max = c[l[i]];
    }
    printf("%d %d\n", max, cnt);
    return 0;
}