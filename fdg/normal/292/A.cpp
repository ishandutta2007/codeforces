#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
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

using namespace std;

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,a,b,last=0,mx=0,tm=0,qs=0;
    scanf("%d",&n);
    for(int i=0;i<n;++i) {
        scanf("%d%d",&a,&b);
        mx=max(mx,qs);
        qs-=min(qs,a-tm);
        qs+=b; tm=a;
        mx=max(mx,qs);
    }
    tm+=qs;
    last=tm;
    printf("%d %d\n",last,mx);
    return 0;
}