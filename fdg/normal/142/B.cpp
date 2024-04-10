#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <ctime>
#include <cmath>

using namespace std;

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,m,ans;
    cin >> n >> m;
    if (n==1||m==1) ans=n+m-1;
    else ans=(n*m+1)/2;
    if (n==2||m==2) {
        int k=n+m-2,r=(k/4)*4+2*min((k&3),2);
        ans=max(ans,r);
    }
    cout << ans << endl;
    return 0;
}