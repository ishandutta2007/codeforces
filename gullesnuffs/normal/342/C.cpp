#include <stdio.h>
#include <cmath>

using namespace std;

int main()
{
    int r, h;
    scanf("%d%d", &r, &h);
    int best=1;
    double hp=double(h)/double(r);
    if(hp > sqrt(3.0)/2.0){
        int t=3+2*floor(hp-sqrt(3.0)/2.0);
        if(t > best)
            best=t;
    }
    if(hp >= 0.5){
        int t=2+2*floor(hp-0.5);
        if(t > best)
            best=t;
    }
    printf("%d\n", best);
    return 0;
}