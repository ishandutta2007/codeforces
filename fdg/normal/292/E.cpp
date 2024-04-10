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

int a[100002],b[100002];
int val[800005];
int x[100005],y[100005],q[100005];

void update(int i,int l,int r,int L,int R,int v) {
    if (l==L&r==R) {
        val[i]=v;
        return;
    }
    if (val[i]!=-1) {
        val[2*i]=val[i];
        val[2*i+1]=val[i];
        val[i]=-1;
    }
    int m=(l+r)>>1;
    if (R<=m) update(2*i,l,m,L,R,v);
    else if (L>m) update(2*i+1,m+1,r,L,R,v);
    else {
        update(2*i,l,m,L,m,v);
        update(2*i+1,m+1,r,m+1,R,v);
    }
}

int find(int i,int l,int r,int pos) {
    if (l==r) return val[i]==-1 ? 0 : val[i];
    if (val[i]!=-1) {
        val[2*i]=val[i];
        val[2*i+1]=val[i];
        val[i]=-1;
    }
    int m=(l+r)>>1;
    if (pos<=m) return find(2*i,l,m,pos);
    else if (pos>m) return find(2*i+1,m+1,r,pos);
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i)
        scanf("%d",&a[i]);
    for(int i=0;i<n;++i)
        scanf("%d",&b[i]);
    memset(val,-1,sizeof(val));
    for(int i=1;i<=m;++i) {
        int t,aa;
        scanf("%d",&t);
        if (t==2) {
            scanf("%d",&aa); --aa;
            int ind=find(1,0,n-1,aa);
            if (ind==0) {
                printf("%d\n",b[aa]);
            } else {
                printf("%d\n",a[x[ind]+(aa-y[ind])]);
            }
        } else {
            scanf("%d%d%d",&x[i],&y[i],&q[i]); --x[i]; --y[i];
            update(1,0,n-1,y[i],y[i]+q[i]-1,i);
        }
    }
    return 0;
}