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

int cnt[1000002];
vector <int> x,y,q;
set < pair <int,int> > f;

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    srand(time(NULL));
    int n,a,nzero=0;
    scanf("%d",&n);
    for(int i=0;i<n;++i) {
        scanf("%d",&a);
        if (a) f.insert(make_pair(a,i));
        cnt[a]++;
        if (a) ++nzero;
    }
    if (nzero<2) {
        puts("-1");
        return 0;
    }
    if (nzero==2) {
        puts("0");
        return 0;
    }
    x.reserve(1000001);
    y.reserve(1000001);
    q.reserve(1000001);
    set < pair <int,int> >::iterator it1,it2;
    for(int i=1;i<=1000000&&nzero>2;++i) {
        if (cnt[i]>=2) {
            --nzero;
            it1=f.lower_bound(make_pair(i,0));
            it2=f.upper_bound(*it1);
            if (it2==f.end()) continue;
            cnt[i]-=2; cnt[2*i]++;
            x.push_back(it1->second); y.push_back(it2->second);
            f.erase(it1); f.erase(it2);
            f.insert(make_pair(2*i,x.back()));
            --i;
        }
    }
    int pt=0;
    while(f.size()>2&&x.size()<=1000000&&nzero>2) {
        it1=f.begin(); it2=f.end(); --it2;
        if (rand()&1) ++it1;
        if (it1==it2) continue;
        x.push_back(it1->second); y.push_back(it2->second);
        cnt[it1->first]--; cnt[it2->first]--;
        int v1=2*it1->first,v2=it2->first-it1->first;
        cnt[v1]++; cnt[v2]++;
        if (v1) f.insert(make_pair(v1,it1->second));
        if (v2) f.insert(make_pair(v2,it2->second));
        f.erase(it1); f.erase(it2);
        if (v1&&cnt[v1]>1) q.push_back(v1);
        if (v2&&cnt[v2]>1) q.push_back(v2);
        while(pt<q.size()&&x.size()<=1000000&&nzero>2) {
            int i=q[pt]; ++pt;
            if (cnt[i]<2) continue;
            --nzero;
            it1=f.lower_bound(make_pair(i,0));
            it2=f.upper_bound(*it1);
            if (it2==f.end()) continue;
            cnt[i]-=2; cnt[2*i]++;
            if (i&&cnt[i]>1) q.push_back(i);
            if (i&&cnt[2*i]>1) q.push_back(2*i);
            x.push_back(it1->second); y.push_back(it2->second);
            f.erase(it1); f.erase(it2);
            if (2*i) f.insert(make_pair(2*i,x.back()));
        }
    }
    if (x.size()>1000000||f.size()!=2) {
        puts("-1");
    } else {
        printf("%d\n",x.size());
        for(int i=0;i<x.size();++i)
            printf("%d %d\n",x[i]+1,y[i]+1);
    }
    return 0;
}