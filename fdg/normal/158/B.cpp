#include <iostream>
#include <cstring>
#include <vector>
#include <ctime>
#include <memory.h>
#include <algorithm>
#include <cstdio>
#include <string>
#include <queue>
#include <cmath>

using namespace std;

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,cnt[5]={0},a;
    scanf("%d",&n);
    for(int i=0;i<n;++i) {
        scanf("%d",&a);
        cnt[a]++;
    }
    int ans=cnt[4]+cnt[3];
    cnt[1]-=cnt[3]; cnt[3]=cnt[4]=0;
    if (cnt[1]<0) cnt[1]=0;
    ans+=cnt[2]>>1; cnt[2]&=1;
    ans+=((cnt[2]*2+cnt[1])%4!=0)+(cnt[2]*2+cnt[1])/4;
    printf("%d\n",ans);
    return 0;
}