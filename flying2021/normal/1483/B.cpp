#include<iostream>
#include<cstdio>
#include<cstring>
#include<set>
#define N 100010
using namespace std;
int gcd(int x,int y){return y==0?x:gcd(y,x%y);}
int a[N];
int L[N],R[N];
set<int>s;
inline bool check(int x){return gcd(a[x],a[R[x]])==1;}
void del(int x)
{
    s.erase(x);
    if(R[x]==x) return;
    if(check(x)) s.erase(R[x]);
    R[L[x]]=R[x];L[R[x]]=L[x];
    if(check(L[x])) s.insert(R[x]);
}
int find_nxt(int x)
{
    if(s.empty()) return -1;
    auto p=s.upper_bound(x);
    if(p==s.end()) return *s.begin();
    return *p;
}
int ans[N],tt;
void clear(){tt=0;s.clear();}
void work(int n)
{
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    L[1]=n;R[n]=1;
    for(int i=1;i<n;i++) R[i]=i+1;
    for(int i=2;i<=n;i++) L[i]=i-1;
    for(int i=1;i<=n;i++) if(check(i)) s.insert(R[i]);
    int p=find_nxt(1);
    while(p!=-1)
    {
        ans[++tt]=p;
        del(p);
        if(s.empty()) break;
        p=find_nxt(R[p]);
    }
    printf("%d",tt);
    for(int i=1;i<=tt;i++) printf(" %d",ans[i]);
    puts("");
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t --> 0)
    {
        clear();
        int n;
        scanf("%d",&n);
        work(n);
    }
    return 0;
}