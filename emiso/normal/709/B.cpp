#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cout << a << endl

using namespace std;

int dist[100100][2],x[100100];

int main() {
    int n,left=0,right=0,pos,ans=99999999,a;
    scanf("%d %d",&n,&a);

    memset(dist,-1,sizeof dist);

    for(int i=0; i<n; i++) {
        scanf("%d",&x[i]);
    }

    sort(x,x+n);
    pos = lower_bound(x,x+n,a) - x;

    dist[0][0] = dist[0][1] = 0;

    for(int i=pos, j = 1; i<n;i++, j++)
        dist[j][1] = abs(x[i] - a);

    for(int i=pos-1, j = 1; i>=0 ;i--, j++)
        dist[j][0] = abs(a - x[i]);

    for(int i=0;i<n;i++) {
        if(dist[i][1] >=0 && dist[n-i-1][0] >=0) {
            ans = min(ans,dist[i][1]*2 + dist[n-i-1][0]);
        }

        if(dist[i][0] >=0 && dist[n-i-1][1] >=0) {
            ans = min(ans,dist[i][0]*2 + dist[n-i-1][1]);
        }
    }

    printf("%d\n",ans);
    return 0;
}