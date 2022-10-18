#include <iostream>
#include <cstring>
#include <vector>
#include <ctime>
#include <memory.h>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <cmath>
#include <map>
#pragma comment(linker,"/STACK:128000000")

using namespace std;

struct item{
    item(int _l1 = 0,int _r1 = 0,int _l2 = 0,int _r2 = 0,int _k = 0) : l1(_l1), l2(_l2), r1(_r1), r2(_r2), k(_k) {};
    int l1,r1,l2,r2,k;
};

bool operator < (const item & a,const item & b) {
    return a.l1<b.l1||
           a.l1==b.l1&&a.r1<b.r1||
           a.l1==b.l1&&a.r1==b.r1&&a.l2<b.l2||
           a.l1==b.l1&&a.r1==b.r1&&a.l2==b.l2&&a.r2<b.r2||
           a.l1==b.l1&&a.r1==b.r1&&a.l2==b.l2&&a.r2==b.r2&&a.k<b.k;
}

map <item,int> f;

int solve(int l1,int r1,int l2,int r2,int k) {
    if (l1>r1||l2>r2||k==0) return 0;
    if (l1==l2&&r1==r2) return r1-l1+1;
    item rr=item(l1,r1,l2,r2,k);
    map<item,int>::iterator it=f.find(rr);
    if (it!=f.end()) return it->second;
    int ans=max(0,min(r1,r2)-max(l1,l2)+1);
    int mid=(1<<(k-1));
    int L1=l1,R1=mid-1,L2=1,R2=r1-mid;
    int L3=l2,R3=mid-1,L4=1,R4=r2-mid;
    if (l1<mid) {
        if (r1<=mid) {
            L1=l1; R1=r1; L2=R2=-1;
            if (r1==mid) R1--;
        } else {
            L1=l1; R1=mid-1;
            L2=1; R2=r1-mid;
        }
    } else {
        L1=l1-mid; R1=r1-mid; L2=R2=-1;
        if (l1==mid) L1++;
    }
    if (l2<mid) {
        if (r2<=mid) {
            L3=l2; R3=r2; L4=R4=-1;
            if (r2==mid) R3--;
        } else {
            L3=l2; R3=mid-1;
            L4=1; R4=r2-mid;
        }
    } else {
        L3=l2-mid; R3=r2-mid; L4=R4=-1;
        if (l2==mid) L3++;
    }
    if (L1<=R1&&L1!=-1) {
        if (L3<=R3&&L3!=-1) ans=max(ans,solve(L1,R1,L3,R3,k-1));
        if (L4<=R4&&L4!=-1) ans=max(ans,solve(L1,R1,L4,R4,k-1));
    }
    if (L2<=R2&&L2!=-1) {
        if (L3<=R3&&L3!=-1) ans=max(ans,solve(L2,R2,L3,R3,k-1));
        if (L4<=R4&&L4!=-1) ans=max(ans,solve(L2,R2,L4,R4,k-1));
    }
    return f[rr]=ans;
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int l1,r1,l2,r2;
    cin >> l1 >> r1 >> l2 >> r2;
    int len=(1<<30)-1;
    cout << solve(l1,r1,l2,r2,30) << endl;
    return 0;
}