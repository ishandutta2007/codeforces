#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define N 5000 + 5
int ans, q[N];
const char st[5] = "bear";
char s[N];
void begin()
{
    scanf("%s", s);
}
bool search(int l, int r, int s1, int t1)
{
    if (l > r) return 0;
    int mid = l + r >> 1;
    if (q[mid] >= s1 && q[mid] <= t1) return 1;
    else if (q[mid] < s1) return search(mid + 1, r, s1, t1);
    else return search(l, mid - 1, s1, t1);
}
void work()
{
    int len = strlen(s);
    for (int i = 0; i < len; i ++)
    {
        bool ok = 1;
        for (int j = 0; j < 4; j ++)
            if (s[i + j] != st[j])
            {
                ok = 0;
                break;
            }
        if (ok == 1) q[++ q[0]] = i;
    }
    for (int i = 0; i < len - 3; i ++)
        for (int j = i; j < len - 3; j ++)
            if (search(1, q[0], i, j)) ans ++;
}
void end()
{
    printf("%d\n", ans);
}
int main()
{
    begin();
    work();
    end();
    return 0;
}