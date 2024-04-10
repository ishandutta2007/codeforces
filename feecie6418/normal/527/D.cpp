#include <iostream>
//shytyuhfueys
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
struct Seg{
    int l,r;
    bool operator <(const Seg a) const {
        if(a.r!=r)return r<a.r;
        return l<a.l; 
    }
}s[200005];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        s[i].l=a-b;
        s[i].r=a+b;
    }
    sort(s+1,s+n+1);
    int rr=-0x7fffffff,ss=0;
    for(int i=1;i<=n;i++){
        if(s[i].l>=rr)rr=s[i].r,ss++;
    }
    cout<<ss;
    return 0;
}