#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <ctime>
#include <cmath>
#include <set>
#include <map>

using namespace std;

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,k;
    scanf("%d%d",&n,&k);
    for(int it=0;it<k;++it) {
        for(int i=1;i<=n;++i) {
            if (i>1) printf(" ");
            if (i<n&&((n-i-1)&(1<<it))) {
                printf("%d",n-(1<<it));
            } else printf("%d",n);
        }
        printf("\n");
    }
    return 0;
}