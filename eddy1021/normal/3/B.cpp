#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100010;

int n, tot;
int in[MAXN];
int car[3][MAXN], cnt[3];
int sum[3][MAXN];

inline bool cmp(int a, int b)
{return in[a] > in[b];}

int main()
{
    scanf("%d%d", &n, &tot);
    for(int i = 1; i <= n; i++)
    {
        int typ;
        scanf("%d%d", &typ, in+i);
        cnt[typ]++;
        car[typ][cnt[typ]] = i;
    }
    sort(car[1]+1, car[1]+cnt[1]+1, cmp);
    sort(car[2]+1, car[2]+cnt[2]+1, cmp);
    for(int i = 1; i <= cnt[1]; i++)
        sum[1][i] = sum[1][i-1] + in[car[1][i]];
    for(int i = 1; i <= cnt[2]; i++)
        sum[2][i] = sum[2][i-1] + in[car[2][i]];
    int ans = 0, a1 = 0, a2 = 0;
    for(int i = 0; i <= cnt[1] && i <= tot; i++)
    {
        int tmp = sum[1][i];
        int cap = (tot - i) / 2;
        cap = max(0, min(cap, cnt[2]));
        //printf("i %d tmp %d cap %d\n", i, tmp, cap);
        if(tmp+sum[2][cap] > ans)
        {
            ans = tmp + sum[2][cap];
            a1 = i;
            a2 = cap;
        }
    }
    printf("%d\n", ans);
    for(int i = 1; i <= a1; i++)
        printf("%d ", car[1][i]);
    for(int i = 1; i <= a2; i++)
        printf("%d ", car[2][i]);
    puts("");
}