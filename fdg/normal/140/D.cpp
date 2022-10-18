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
    int n,tm[102]={0};
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> tm[i];
    sort(tm,tm+n);
    int cnt=0,ans=0,cur=10;
    for(int i=0;i<n;i++) {
        if (cur+tm[i]<=720) {
            cnt++; cur+=tm[i];
            if (cur>360) ans+=cur-360;
        }
    }
    cout << cnt << " " << ans << endl;
    return 0;
}