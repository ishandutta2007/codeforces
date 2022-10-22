#include <stdio.h>
#include <complex>
#include <math.h>
#include <algorithm>

using namespace std;

complex<int> flam[300];

long long Abs(long long a){
    return a<0?-a:a;
}

int ans[1000005];

int main()
{
    int binoN, flamN;
    scanf("%d%d", &binoN, &flamN);
    for(int i=0; i < flamN; ++i){
        int x, y;
        scanf("%d%d", &x, &y);
        flam[i]=complex<int>(x, y);
    }
    for(int i=1; i <= binoN; ++i)
        ans[i]=1;
    for(int i=0; i < flamN; ++i){
        for(int j=i+1; j < flamN; ++j){
            if(imag(flam[i]) == imag(flam[j]))
                continue;
            int n=2;
            long long x[2][2];
            x[1][0]=real(flam[j]-flam[i]);
            x[1][1]=imag(flam[j]-flam[i]);
            for(int k=j+1; k < flamN; ++k){
                x[0][0]=real(flam[k]-flam[i]);
                x[0][1]=imag(flam[k]-flam[i]);
                if(x[0][1]*x[1][0]-x[0][0]*x[1][1] == 0)
                    ++n;
            }
            long long pos;
            x[0][0]=real(flam[i]);
            x[0][1]=imag(flam[i]);
            x[1][0]=real(flam[j]);
            x[1][1]=imag(flam[j]);
            if(Abs(x[0][0]*x[1][1]-x[0][1]*x[1][0])%Abs(x[0][1]-x[1][1]))
                continue;
            pos=(x[0][0]*x[1][1]-x[0][1]*x[1][0])/(x[1][1]-x[0][1]);
            if(pos >= 1 && pos <= binoN && n > ans[pos])
                ans[pos]=n;
        }
    }
    long long answer=0;
    for(int i=1; i <= binoN; ++i)
        answer += ans[i];
    printf("%I64d", answer);
    return 0;
}