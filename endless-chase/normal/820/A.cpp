#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <string.h>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <list>
#include <bitset>
#include <stack>
#include <stdlib.h>
#define lowbit(x) (x&-x)
#define e exp(1.0)
#define eps 1e-8

typedef long long ll;
typedef long long LL;
using namespace std;
typedef unsigned long long ull;
int main()
{
    ios::sync_with_stdio(false);
    int c,v0,v1,a,l,ans;
    while(cin>>c>>v0>>v1>>a>>l)
    {
        ans=0;
        int n=c;
        int v;
        while(n>0)
        {
            if(ans!=0) n=n+l;
            v=min(v0+a*ans,v1);
            n=n-v;
            ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}