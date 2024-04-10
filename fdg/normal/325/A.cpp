#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>

using namespace std;

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n;
    scanf("%d",&n);
    int x1[9],y1[9],x2[9],y2[9];
    long long total=0; int mx=1000000,my=1000000;
    for(int i=0;i<n;++i) {
        scanf("%d%d%d%d",&x1[i],&y1[i],&x2[i],&y2[i]);
        mx=min(mx,min(x1[i],x2[i]));
        my=min(my,min(y1[i],y2[i]));
        total+=1LL*(x2[i]-x1[i])*(y2[i]-y1[i]);
    }
//  cout << total << endl;
/*  for(int mask=1;mask<(1<<n);++mask) {
        int lx=0,rx=1000000,ly=0,ry=1000000,cnt=0;
        for(int i=0;i<n;++i)
            if (mask&(1<<i)) {
                ++cnt;
                lx=max(lx,x1[i]);
                rx=min(rx,x2[i]);
                ly=max(ly,y1[i]);
                ry=min(ry,y2[i]);
            }
        if (lx<=rx&&ly<=ry) {
            total+=((cnt&1) ? 1 : -1)*((rx-lx+1)*(1+(ry>ly))+((ry>ly) ? (ry-ly-1)*(1+(rx>lx)) : 0));
        }
    }
    cout << total << endl;
*/  int side=sqrt(total+1e-6);
    if (1LL*side*side==total) {
        bool ok=true;
        int lx=mx,rx=mx+side,ly=my,ry=my+side;
        for(int i=0;i<n;++i)
            if (x1[i]<lx||x2[i]>rx||y1[i]<ly||y2[i]>ry) ok=false;
        puts(ok ? "YES" : "NO");
    } else puts("NO");
    return 0;
}