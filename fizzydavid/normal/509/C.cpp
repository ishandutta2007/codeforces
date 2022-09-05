//while(true)rp++;
#include<bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<"="<<x<<endl;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
int n,a[311],sz[311];
int b[311][411];
void inc(int id,int digit)
{
    b[id][digit]++;
    int i=digit;
    while(b[id][i]>9)
    {
        b[id][i]=0;
        b[id][++i]++;
    }
    sz[id]=max(sz[id],i+1);
}
int cal(int id)
{
    int ans=0;
    for(int i=0;i<=400;i++)ans+=b[id][i];
    return ans;
}
void out(int i)
{
    for(int j=sz[i]-1;j>=0;j--)cout<<b[i][j];cout<<endl;
}
void num(int id,int x)
{
    int s=sz[id];
    if(s==0)
    {
        while(x>0)
        {
            b[id+1][sz[id+1]++]=min(x,9);
            x-=9;
        }
    }
    else
    {
        int sum=0;sz[id+1]=s;
        for(int i=0;i<s;i++)b[id+1][i]=b[id][i];
        inc(id+1,0);
        sum=cal(id+1);
        int tmp=0;
        while(sum>x)
        {
            while(b[id+1][tmp]==0)tmp++;
            b[id+1][tmp]=0;
            inc(id+1,tmp+1);
            sum=cal(id+1);
        }
        tmp=0;
        while(sum<x)
        {
            b[id+1][tmp]=min(9,b[id+1][tmp]+x-sum);
            tmp++;
            sum=cal(id+1);
            sz[id+1]=max(sz[id+1],tmp);
        }
    }
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)num(i-1,a[i]);
    for(int i=1;i<=n;i++)out(i);
    return 0;
}