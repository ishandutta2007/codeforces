#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <memory.h>
#include <string.h>

using namespace std;

int a[100005],d[100005];

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i)
        scanf("%d",&a[i]);
    d[0]=-1000000000;
    for(int i=1;i<=n+2;++i)
        d[i]=1000000000;
    for(int i=0;i<n;i++) {
        int j=int(upper_bound (d, d+n+1, a[i]) - d);
        if (d[j-1]<a[i]&&a[i]<d[j])
            d[j]=a[i];
    }
    for(int i=n;i>=0;--i)
        if (d[i]!=1000000000) {
            printf("%d\n",i);
            break;
        }
    return 0;
}