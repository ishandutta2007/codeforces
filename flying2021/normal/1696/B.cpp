#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#define N 100010
using namespace std;
int a[N];
int main()
{
    int t;
    scanf("%d",&t);
    while(t --> 0)
    {
        int n;scanf("%d",&n);
        int c=0;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),c+=a[i]==0;
        if(c==n) puts("0");
        else
        {
            int l=1;
            while(l<=n && a[l]==0) l++;
            while(l<=n && a[l]) l++;
            while(l<=n && a[l]==0) l++;
            if(l>n) puts("1");
            else puts("2");
        }
    }
    return 0;
}