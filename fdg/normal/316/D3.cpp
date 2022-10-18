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
#include <queue>
#include <memory.h>

using namespace std;

set < int > f;

int to(vector <int> v) {
    int ret=0;
    for(int i=0;i<v.size();++i)
        ret=ret*(v.size()+1)+v[i]+1;
    return ret;
}

void go(vector <int> init,vector <int> v) {
    f.insert(to(init));
    for(int i=0;i<v.size();++i)
        if (v[i])
            for(int j=i+1;j<v.size();++j)
                if (v[j]) {
                    v[i]--; v[j]--;
                    swap(init[i],init[j]);
                    go(init,v);
                    swap(init[i],init[j]);
                    v[i]++; v[j]++;
                }
}

int a[1000006];

int mod=1000000007;

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n;
    scanf("%d",&n);
    int two=0,aa;
    for(int i=0;i<n;++i) {
        scanf("%d",&aa);
        if (aa==2) ++two;
    }
    two=min(two,max(n-2,0));
/*  vector <int> v(n),init(n);
    for(int i=0;i<v.size();++i) {
        scanf("%d",&v[i]);
        init[i]=i;
    }
    go(init,v);
    cout << f.size() << endl;
*/  a[1]=1; a[2]=2; a[3]=4;
    for(int i=4;i<=1000000;++i)
        a[i]=(a[i-1]+1LL*(i-1)*a[i-2])%mod;
    int start=a[n-two],cur=n-two+1;
    for(int i=0;i<two;++i) {
        start=1LL*start*cur%mod;
        cur++;
    }
    cout << start << endl;
    return 0;
}