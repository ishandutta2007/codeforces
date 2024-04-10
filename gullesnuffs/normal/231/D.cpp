#include <stdio.h>

using namespace std;

int main()
{
    int vx, vy, vz;
    scanf("%d%d%d", &vx, &vy, &vz);
    int bx, by, bz;
    scanf("%d%d%d", &bx, &by, &bz);
    int a[7];
    for(int i=1; i < 7; ++i)
        scanf("%d", a+i);
    int ans=0;
    if(vy < 0)
        ans += a[1];
    if(vy > by)
        ans += a[2];
    if(vz < 0)
        ans += a[3];
    if(vz > bz)
        ans += a[4];
    if(vx < 0)
        ans += a[5];
    if(vx > bx)
        ans += a[6];
    printf("%d", ans);
    return 0;
}