#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <queue>
#include <ctime>
#include <map>
#include <set>
#pragma comment (linker,"/STACK:256000000")

using namespace std;

pair <int,int> get(long long n) {
    pair <int,int> ret;
    int a=max((int)sqrt(0.0+n)-5,0);
    while((1+a)*1LL*(1+a)<=n) ++a;
    ret.second=min((long long)a,n-1);
    a=(int)pow(0.0+n,0.25)+5;
    while(true) {
        long long val=1LL*(a-1)*(a-1)*(a-1)*(a-1);
        if (val>=n) --a;
        else break;
    }
    ret.first=max(a,0);
    return ret;
}

int l[7]={0,4,16,82,6724,50626},
    r[7]={3,15,81,6723,50625,1000000},
    v[7]={0,1,2,0,3,1};

int impr2(long long n) {
    if (n<=1000000) {
        for(int i=0;i<6;++i)
            if (l[i]<=n&&n<=r[i]) return v[i];
    }
    pair <int,int> p=get(n);
    bool ok[5]={0};
    for(int i=0;i<6;++i) {
        int ll=max(p.first,l[i]),rr=min(p.second,r[i]);
        if (ll<=rr) ok[v[i]]=true;
    }
    for(int i=0;;++i)
        if (!ok[i]) return i;
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,res=0;
    long long a;
    scanf("%d",&n);
    for(int i=0;i<n;++i) {
        scanf("%I64d",&a);
        res^=impr2(a);
    }
    if (res) puts("Furlo");
    else puts("Rublo");
    return 0;
}