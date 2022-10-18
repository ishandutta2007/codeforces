#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <ctime>
#include <memory.h>
#include <string>
#include <sstream>
#include <map>

#define ll long long

using namespace std;

struct item{
    int m,v,num;
};

bool operator < (const item & a,const item & b) {
    return a.m<b.m||a.m==b.m&&a.v<b.v||a.m==b.m&&a.v==b.v&&a.num<b.num;
}

item v[100005];

int n,k,h;
const double eps=1e-6;

bool can(double t) {
    int cur=0;
    for(int i=1;i<=k;++i) {
        while(cur<n&&1.0*i*h/v[cur].v>t+eps) ++cur;
        if (cur==n) return false;
        ++cur;
    }
    return true;
}

void output(double t) {
    int cur=0;
    for(int i=1;i<=k;++i) {
        while(cur<n&&1.0*i*h/v[cur].v>t+eps) ++cur;
        if (i!=1) printf(" ");
        printf("%d",v[cur].num);
        ++cur;
    }
    printf("\n");
}

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    scanf("%d%d%d",&n,&k,&h);
    for(int i=0;i<n;++i) {
        scanf("%d",&v[i].m);
        v[i].num=i+1;
    }
    for(int i=0;i<n;++i)
        scanf("%d",&v[i].v);
    sort(v,v+n);
    double l=-1,r=1000000009;
    for(int t=0;t<200;++t) {
        double m=(l+r)/2;
        if (can(m)) r=m;
        else l=m;
    }
//  cout << r << endl;
    output(r);
    return 0;
}