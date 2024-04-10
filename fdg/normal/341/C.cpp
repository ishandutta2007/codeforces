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

int n,arr[2002];
int mod=1000000007;
int fact[2002],un[2002],up[2002];
int C[2002][2002];

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    scanf("%d",&n);
    int total=0;
    for(int i=0;i<n;++i) {
        scanf("%d",&arr[i]);
        if (arr[i]!=-1) {
            un[arr[i]-1]=true;
            up[i]=true;
        } else ++total;
    }
    for(int i=0;i<=n;++i) {
        C[i][0]=1;
        for(int j=1;j<=i;++j)
            C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
    }
    fact[0]=fact[1]=1;
    for(int i=2;i<=n;++i)
        fact[i]=1LL*i*fact[i-1]%mod;
    int cnt=0;
    for(int i=0;i<n;++i)
        if (!un[i]&&!up[i]) ++cnt;
    int ans=fact[total];
    for(int i=1;i<=cnt;++i) {
        int sgn=(i&1) ? -1 : 1;
        ans=(ans+sgn*(1LL*C[cnt][i]*fact[total-i])%mod+mod)%mod;
    }
    cout << ans << endl;
    return 0;
}