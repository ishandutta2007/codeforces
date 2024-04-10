#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cout << a << endl

using namespace std;

inline int mabs(int a) {
    return (a>0)?a:-a;
}

int main() {
    int n,a,b,v,x,y;
    double best = 99999999;
    scanf("%d %d",&a,&b);
    scanf("%d",&n);
    for(int i=0; i<n; i++) {
        scanf("%d %d %d",&x,&y,&v);
        best = min(best,sqrt(mabs(x-a)*mabs(x-a) + mabs(y-b)*mabs(y-b))/(1.0*v));
    }

    printf("%.9f\n",best);
    return 0;
}