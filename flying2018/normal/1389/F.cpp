#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#define ll long long
#define N 400010
using namespace std;
struct node{
    int l,r,t;
    bool operator<(node b)const{return r<b.r || (r==b.r && l<b.l);}
}a[N];
multiset<int>s[2];
int main()
{
    int n,ans=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d%d%d",&a[i].l,&a[i].r,&a[i].t),a[i].t--;
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        auto t=s[a[i].t^1].lower_bound(a[i].l);
        if(t==s[a[i].t^1].end()) s[a[i].t].insert(a[i].r);
        else ++ans,s[a[i].t^1].erase(t);
    }
    printf("%d\n",n-ans);
    return 0;
}