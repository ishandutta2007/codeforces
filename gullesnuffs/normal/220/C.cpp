#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <map>
#include <vector>

using namespace std;

int n, a[100005], b[100005], pos[100005][2], f[100005];

map<int, int> increase, decrease;
pair<int, int> ev[200005];

int main()
{
    scanf("%d", &n);
    for(int i=0; i < n; ++i){
        scanf("%d", a+i);
        pos[a[i]-1][0]=i;
    }
    for(int i=0; i < n; ++i){
        scanf("%d", b+i);
        pos[b[i]-1][1]=i;
    }
    for(int i=0; i < n; ++i){
        if(pos[i][0] >= pos[i][1]){
            increase[pos[i][0]-pos[i][1]]++;
            f[i]=pos[i][0]-pos[i][1];
        }
        else{
            decrease[pos[i][1]-pos[i][0]]++;
            f[i]=pos[i][1]-pos[i][0];
        }
        ev[2*i]=make_pair(pos[i][1], 2*i);
        ev[2*i+1]=make_pair((pos[i][1]-pos[i][0]+n-1)%n, 2*i+1);
    }
    sort(ev, ev+2*n);
    int evPos=0;
    for(int i=0; i < n; ++i){
        int b1, b2;
        if(increase.empty())
            b1=n;
        else
            b1=increase.begin()->first+i;
        if(decrease.empty())
            b2=n;
        else
            b2=decrease.begin()->first-i;
        int best=min(b1, b2);
        printf("%d\n", best);
        while(evPos < 2*n && ev[evPos].first == i){
            int j=ev[evPos].second/2;
            if(ev[evPos].second&1){
                //a[i]=b[i]
                --decrease[f[j]];
                if(decrease[f[j]] == 0)
                    decrease.erase(f[j]);
                f[j]=-i-1;
                ++increase[f[j]];
            }
            else{
                --increase[f[j]];
                if(increase[f[j]] == 0)
                    increase.erase(f[j]);
                f[j]=n+pos[j][1]-pos[j][0];
                ++decrease[f[j]];
            }
            ++evPos;
        }
    }
    return 0;
}