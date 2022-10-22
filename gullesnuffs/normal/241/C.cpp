#include <stdio.h>
#include <complex>
#include <map>
#define EPS 1e-8

using namespace std;

int mV[105], mPos[105], mL[105], mR[105];
map<int, bool> usedHeight;
bool usedM[105];

int main()
{
    int hL, hR, mN;
    scanf("%d%d%d", &hL, &hR, &mN);
    hL -= 50;
    hR -= 50;
    for(int i=0; i < mN; ++i){
        char input[2];
        scanf("%d%s%d%d", mV+i, input, mL+i, mR+i);
        mPos[i]=input[0];
    }
    complex<double> start(0, hL);
    int ans=0;
    for(int i=-mN; i <= mN; ++i){
        complex<double> goal(100000, hR);
        if((i+200)%2 == 0)
            goal=complex<double>(100000, hR+i*100);
        else
            goal=complex<double>(100000, -hR+i*100);
        for(int j=0; j < mN; ++j)
            usedM[j]=0;
        for(int j=-mN*100-50; j <= mN*100+50; j += 100)
            usedHeight[j]=0;
        bool ok=1;
        for(int j=0; j < mN; ++j)
            for(int k=-mN/2-1; 2*k <= mN; ++k){
                if(goal.imag()-start.imag() == 0)
                    continue;
                double x, y;
                int yy;
                yy=(mPos[j]=='F'?(-50):50)+k*200;
                y=(mPos[j]=='F'?(-50):50)+k*200;
                x=((y-start.imag())/(goal.imag()-start.imag()))*(goal.real());
                if(x+EPS > mL[j] && x-EPS < mR[j]){
                    if(usedM[j]){
                        ok=0;
                    }
                    else{
                        usedM[j]=1;
                        usedHeight[yy]=1;
                    }
                }
            }
        for(int j=50; j < goal.imag(); j += 100)
            if(!usedHeight[j])
                ok=0;
        for(int j=-50; j > goal.imag(); j -= 100)
            if(!usedHeight[j])
                ok=0;
        if(!ok)
            continue;
        int sum=0;
        for(int j=0; j < mN; ++j)
            if(usedM[j])
                sum += mV[j];
        if(sum > ans)
            ans=sum;
    }
    printf("%d", ans);
    return 0;
}