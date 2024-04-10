#include <stdio.h>
#include <algorithm>

using namespace std;

int n;
int p[2][100005];
int q[2][100005];
bool type[2][2];

int main()
{
    scanf("%d", &n);
    for(int i=0; i < n; ++i){
        scanf("%d%d", q[0]+i, q[1]+i);
        p[0][i]=q[0][i];
        p[1][i]=q[1][i];
    }
    for(int i=0; i < 2; ++i)
        for(int j=0; j < 2; ++j)
            type[i][j]=0;
    long long best=-1;
    long long ans=0;
    for(int i=0; i < 2; ++i){
        nth_element(p[i], p[i]+n/2, p[i]+n);
        int median=p[i][n/2];
        for(int j=n/2+1; j < n; ++j){
            if(best == -1 || p[i][j]-median < best){
                if(n%2)
                    best=p[i][j]-median;
            }
            ans += p[i][j]-median;
        }
        for(int j=0; j < n/2; ++j){
            if(best == -1 || median-p[i][j] < best){
                best=median-p[i][j];
            }
            ans += median-p[i][j];
        }
    }
    int nGood=0;
    for(int i=0; i < n; ++i){
        if((q[0][i] == p[0][n/2] || q[1][i] == p[1][n/2]) && n%2)
            ++nGood;
        else
            type[q[0][i] < p[0][n/2]][q[1][i] < p[1][n/2]]=1;
    }
    if(nGood >= 2 && n%2)
        best=0;
    if(!type[0][0] && !type[1][1])
        best=0;
    if(!type[0][1] && !type[1][0])
        best=0;
    printf("%I64d", 2*(ans-best));
    return 0;
}