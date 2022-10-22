#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
    int acc=4, v=0;
    pair<int, int> ev[8];
    int n, c, x, y;
    scanf("%d%d%d%d", &n, &x, &y, &c);
    --x;
    --y;
    ev[0]=make_pair(x, -2);
    ev[1]=make_pair(y, -2);
    ev[2]=make_pair(n-x-1, -2);
    ev[3]=make_pair(n-y-1, -2);
    ev[4]=make_pair(x+y, 1);
    ev[5]=make_pair(n-x-1+y, 1);
    ev[6]=make_pair(x+n-y-1, 1);
    ev[7]=make_pair(n-x-1+n-y-1, 1);
    sort(ev, ev+8);
    int t=1, e=0;
    for(int i=0; true; ++i){
        if(t >= c){
            printf("%d", i);
            return 0;
        }
        while(e < 8 && ev[e].first == i){
            if(ev[e].second == -2)
                v += 1;
            else
                v -= 1;
            acc += ev[e].second;
            ++e;
        }
        v += acc;
        t += v;
    }
    return 0;
}