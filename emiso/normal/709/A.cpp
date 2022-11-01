#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cout << a << endl

using namespace std;

int main() {
    int n,cap=0,b,d,ans=0,a;
    scanf("%d %d %d",&n,&b,&d);

    for(int i=0; i<n; i++) {
        scanf("%d",&a);
        if(a <= b) {
            cap += a;
            if(cap > d) {
                cap = 0;
                ans++;
            }
        }
    }

    printf("%d\n",ans);
    return 0;
}