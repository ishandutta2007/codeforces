#include <iostream>
#include <cstring>
#include <vector>
#include <ctime>
#include <memory.h>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <cmath>

using namespace std;

int arr[20002];

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,ans=0;
    scanf("%d",&n);
    for(int i=0;i<n;++i) {
        scanf("%d",&arr[i]);
        ans+=arr[i];
    }
    for(int i=3;i<=n;++i)
        if (n%i==0) {
            for(int j=n/i-1;j>=0;--j) {
                int cur=0,d=n/i;
                for(int l=j;l<n;l+=d) {
                    cur+=arr[l];
                }
                ans=max(ans,cur);
            }
        }
    printf("%d\n",ans);
    return 0;
}