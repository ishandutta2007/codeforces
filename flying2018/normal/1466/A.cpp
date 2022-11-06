#include<iostream>
#include<cstdio>
#include<cstring>
#include<set>
#define N 60
using namespace std;
int a[N];
set<int>s;
int main()
{
    int t;
    scanf("%d",&t);
    while(t --> 0)
    {
        int n;
        scanf("%d",&n);
        s.clear();
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            if(a[i]!=a[j]) s.insert(abs(a[i]-a[j]));
        printf("%d\n",(int)s.size());
    }
    return 0;
}