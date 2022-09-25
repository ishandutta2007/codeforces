#include <cstdio>
#include <algorithm>
using namespace std;
int pos[105];
int ladder[105];
double expected[105];
int main(){
    for (int x=0;x<10;x++){
        for (int y=0;y<10;y++){
            if (x&1) pos[x*10+y]=10*x+y;
            else pos[x*10+9-y]=10*x+y;
        }
    }
    int t;
    for (int x=99;x>=0;x--){
        scanf("%d",&t);
        ladder[pos[x]]=pos[x+t*10];
    }

    for (int x=0;x<98;x++) expected[x]=1;
    expected[99]=0;
    double now;
    for (int x=98;x>=94;x--){
        for (int _x=0;_x<10000;_x++){
            now=0;
            for (int z=x+1;z<=x+6;z++){
                if (z>99) now+=(1+expected[x])/6;
                else now+=(1+expected[z])/6;
            }
            expected[x]=now;
        }
    }
    for (int x=93;x>=0;x--){
        now=0;
        for (int z=x+1;z<=x+6;z++){
            now+=(1+min(expected[z],expected[ladder[z]]))/6;
        }
        expected[x]=now;
    }

    printf("%.8f\n",now);
}