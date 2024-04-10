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
    int n,a;
    scanf("%d",&n);
    map <int,int> f;
    for(int i=0;i<n;++i) {
        scanf("%d",&a);
        if (a) f[a]++;
    }
    int ans=0;
    for(map <int,int>::iterator it=f.begin();it!=f.end();++it) {
        if (it->second>2) {
            puts("-1");
            return 0;
        } else if (it->second==2) ++ans;
    }
    printf("%d\n",ans);
    return 0;
}