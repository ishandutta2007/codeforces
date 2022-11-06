#include<iostream>
#include<cstdio>
#define N 100010
#define ll long long
#define D 35
using namespace std;
ll num[N];
int main()
{
    int t;
    scanf("%d",&t);
    while(t --> 0)
    {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%lld",&num[i]);
        int win=0;
        for(int i=D;i>=0 && win==0;i--)
        {
            int tot=0;
            for(int j=1;j<=n;j++)
            if((num[j]>>i)&1) ++tot;
            if(tot%2==0) continue;
            if(tot%4==1) win=1;
            else win=(n-tot)%2==1?1:-1;
        }
        puts(win==1?"WIN":(win==0?"DRAW":"LOSE"));
    }
}