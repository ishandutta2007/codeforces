#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <cstdlib>
#include <complex>
#include <cassert>
using namespace std;

int main()
{
    int n, c;
    int x[105];
    scanf("%d%d", &n, &c);
    int ans=0;
    for(int i=0; i < n; ++i){
        scanf("%d", x+i);
        if(i){
            int t=x[i-1]-x[i]-c;
            ans=max(ans, t);
        }
    }
    printf("%d\n", ans);
    return 0;
}