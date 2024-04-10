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

int mod=1000000000;
int arr[200005],fib[200005],sfib[200005];

struct item {
    item(int val = 0) : s0(val), s1(val), add(0), len(1) {};
    int s0,s1,add,len;
    int get(int x) {
        int plus=1LL*(sfib[len-1+x]-(x>0 ? sfib[x-1] : 0)+mod)*add%mod;
        if (x==0) return (s0+plus)%mod;
        if (x==1) return (s1+plus)%mod;
        return (1LL*s0*fib[x-2]+1LL*s1*fib[x-1]+plus)%mod;
    }
};

item tree[4*200005];

item combine(item & a,item & b) {
    item ret;
    ret.s0=(a.get(0)+b.get(a.len))%mod;
    ret.s1=(a.get(1)+b.get(a.len+1))%mod;
    ret.len=a.len+b.len;
    return ret;
}

void build(int i,int l,int r) {
    if (l==r) tree[i]=item(arr[l]);
    else {
        int m=(l+r)>>1;
        build(2*i,l,m);
        build(2*i+1,m+1,r);
        tree[i]=combine(tree[2*i],tree[2*i+1]);
    }
}

void addmod(int & res,int a) {
    res=(res+a)%mod;
}

item get(int i,int l,int r,int L,int R) {
    if (tree[i].add) {
        tree[i].s0=tree[i].get(0);
        tree[i].s1=tree[i].get(1);
        if (l<r) {
            addmod(tree[2*i].add,tree[i].add);
            addmod(tree[2*i+1].add,tree[i].add);
        }
        tree[i].add=0;
    }
    if (l==L&&r==R) return tree[i];
    int m=(l+r)>>1;
    if (R<=m) return get(2*i,l,m,L,R);
    if (L>m) return get(2*i+1,m+1,r,L,R);
    return combine(get(2*i,l,m,L,m),get(2*i+1,m+1,r,m+1,R));
}

void update(int i,int l,int r,int L,int R,int val) {
    if (tree[i].add) {
        tree[i].s0=tree[i].get(0);
        tree[i].s1=tree[i].get(1);
        if (l<r) {
            addmod(tree[2*i].add,tree[i].add);
            addmod(tree[2*i+1].add,tree[i].add);
        }
        tree[i].add=0;
    }
    if (l==L&&r==R) tree[i].add=(tree[i].add+val)%mod;
    else {
        int m=(l+r)>>1;
        if (R<=m) update(2*i,l,m,L,R,val);
        else if (L>m) update(2*i+1,m+1,r,L,R,val);
        else {
            update(2*i,l,m,L,m,val);
            update(2*i+1,m+1,r,m+1,R,val);
        }
        tree[i]=combine(tree[2*i],tree[2*i+1]);
    }
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i)
        scanf("%d",&arr[i]);
    fib[0]=fib[1]=1;
    for(int i=2;i<=n;++i)
        fib[i]=(fib[i-1]+fib[i-2])%mod;
    for(int i=0;i<=n;++i) {
        sfib[i]=fib[i];
        if (i) sfib[i]=(sfib[i]+sfib[i-1])%mod;
    }
    build(1,0,n-1);
    while(m--) {
        int t,l,r,d;
        scanf("%d%d%d",&t,&l,&r);
        if (t==1) {
            --l;
            update(1,0,n-1,l,l,r-get(1,0,n-1,l,l).get(0));
        } else if (t==2) {
            --l; --r;
            printf("%d\n",get(1,0,n-1,l,r).get(0));
        } else {
            scanf("%d",&d);
            --l; --r;
            update(1,0,n-1,l,r,d);
        }
    }
    return 0;
}