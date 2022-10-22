#include <stdio.h>

using namespace std;

int main()
{
    int roadN, waitTime, cityN;
    scanf("%d%d", &roadN, &waitTime);
    cityN=roadN+1;
    int dis[1005], refill[1005];
    for(int i=0; i < roadN; ++i)
        scanf("%d", dis+i);
    for(int i=0; i < roadN; ++i)
        scanf("%d", refill+i);
    int fuel, time, MaxRefill=0;
    time=0;
    fuel=refill[0];
    MaxRefill=refill[0];
    refill[roadN]=0;
    for(int i=0; i < roadN; ++i){
        while(fuel < dis[i]){
            fuel += MaxRefill;
            time += waitTime;
        }
        fuel -= dis[i];
        fuel += refill[i+1];
        time += dis[i];
        if(refill[i+1] > MaxRefill)
            MaxRefill=refill[i+1];
    }
    printf("%d", time);
    return 0;
}