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

int a[302][302];

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    int my[302]={0},ans[302]={0};
    for(int i=0;i<n;i++)
        scanf("%d",&my[i]);
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if (a[i][j]==i+1) continue;
            int cnt=0; bool was=false;
            for(int t=0;t<n;t++) {
                if (was&&my[t]<a[i][j]&&my[t]!=i+1) cnt++;
                if (my[t]==a[i][j]) was=true;
            }
            if (i+1<a[i][j]) cnt++;
            if (cnt+1==a[i][j]) {
                ans[i]=a[i][j];
                break;
            }
        }
    }
    printf("%d",ans[0]);
    for(int i=1;i<n;i++)
        printf(" %d",ans[i]);
    printf("\n");
    return 0;
}