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

int a[10002],b[10002];

struct item {
    int l,r,i;
};

bool operator < (const item & a,const item & b) {
    return a.l<b.l||a.l==b.l&&a.r>b.r;
}

item v[20002];
int ans[20002];
int color[502],cnt=0;
int tmp[502],tcnt=0;

inline int repr(int * col,int x) {
    return col[x]==x ? x : col[x]=repr(col,col[x]);
}

inline void join(int * col,int x,int y,int & res) {
    x=repr(col,x); y=repr(col,y);
    if (x!=y) {
        col[x]=y;
        --res;
    }
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;++i) {
        scanf("%d%d",&a[i],&b[i]); --a[i]; --b[i];
    }
    int k,l,r;
    scanf("%d",&k);
    for(int i=0;i<k;++i) {
        scanf("%d%d",&l,&r); --l; --r;
        v[i].l=l; v[i].r=r; v[i].i=i;
    }
    sort(v,v+k);
    for(int i=0;i<n;++i) color[i]=i; cnt=n;
    int last=0;
    for(int j=0;j<k;) {
        while(last<v[j].l) {
            join(color,a[last],b[last],cnt);
            ++last;
        }
        memcpy(tmp,color,sizeof(color)); tcnt=cnt;
        int ll=v[j].l,rr=m-1;
        while(j<k&&v[j].l==ll) {
            while(rr>v[j].r) {
                join(tmp,a[rr],b[rr],tcnt);
                --rr;
            }
            ans[v[j].i]=tcnt;
            ++j;
        }
    }
    for(int i=0;i<k;++i)
        printf("%d\n",ans[i]);
    return 0;
}