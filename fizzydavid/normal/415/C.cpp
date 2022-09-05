#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<ctime>
#include<utility>
#include<vector>
using namespace std; 
long long n,k;
int x;
int main()
{
    cin>>n>>k;
    if(k<n/2||n==1&&k!=0)
    {
        cout<<-1;
    }
    else if(n==1&&k==0)
    {
        cout<<1;
    }
    else
    {
        long long c=k-n/2+1;long long a1=c*2,a2=c*3;x=2;
        cout<<c*2<<" "<<c*3;
        for(long long i=3;i<n;i+=2)
        {
            x+=2;
            while(x==a1||x==a2||x+1==a1||x+1==a2)x++;
            printf(" %d %d",x,x+1);
        }
        if(n&1)cout<<" "<<1;
    }
    return 0;
}