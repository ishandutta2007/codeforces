#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <vector>
#define INF 999999999
using namespace std;

int a[35][35];

int main()
{
    int n, x;
    scanf("%d", &n);
    for(int i=0; i < n; ++i)
        for(int j=0; j < n; ++j)
            scanf("%d", a[i]+j);
    x=(n+1)/2;
    int ans=-INF;
    for(int i=0; i < 1<<x; ++i){
        int sum=0;
        long long j=i&1;
        for(int p=0; p < x-1; ++p){
            if((j&(1LL<<p) && !(i&(1LL<<(p+1)))) || (!(j&(1LL<<p)) && i&(1LL<<(p+1))))
                j ^= (1LL<<(p+1));
        }
        for(int p=x-1; p < n; ++p){
            if((j&(1LL<<p) && !(i&(1LL<<((p-x)+1)))) || (!(j&(1LL<<p)) && i&(1LL<<((p-x)+1))))
                j ^= (1LL<<(p+1));
        }
        for(int c=0; c < x-1; ++c){
            int best=-INF;
            for(int d=0; d < 2; ++d){
                /*if(d)
                    j^=(1LL<<x)-1;*/
                int tmpsum=0;
                for(int r=0; r < x-1; ++r){
                    int y1=a[r][c];
                    if(j&(1LL<<r))
                        y1 *= -1;
                    y1 += a[r][c+x];
                    if(d)
                        y1 *= -1;
                    int y2=a[r+x][c];
                    if(j&(1LL<<(r+x)))
                        y2 *= -1;
                    y2 += a[r+x][c+x];
                    tmpsum += abs(y1+y2);
                }
                int z1=a[x-1][c];
                if(j&(1LL<<(x-1)))
                    z1 *= -1;
                z1 += a[x-1][c+x];
                if(d)
                    tmpsum += -z1;
                else
                    tmpsum += z1;
                if(tmpsum > best)
                    best=tmpsum;
            }
            sum += best;
        }
        for(int r=0; r < n; ++r){
            if(j&(1LL<<r))
                sum -= a[r][x-1];
            else
                sum += a[r][x-1];
        }
        /*if(i&(1<<(x-1)))
            sum -= a[x-1][x-1];
        else
            sum += a[x-1][x-1];*/
        if(sum > ans)
            ans=sum;
    }
    printf("%d\n", ans);
    return 0;
}