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
#include<utility>
#include<vector>
using namespace std;
#define LL long long 
LL t;
bool isp(LL x){for(LL i=2;i*i<=x;i++)if(x%i==0)return 0;return !(x<2);}
LL gcd(LL x,LL y){if(y!=0)return gcd(y,x%y);else return x;}
int main()
{
    cin>>t;
    while(t--)
    {
        LL n;
        cin>>n;
        LL s1,s2,dp=n,up=n+1;
        while(!isp(dp))dp--;while(!isp(up))up++;
        s1=dp*up-2*(dp+up-n-1);s2=dp*up*2;
        LL g=gcd(s1,s2);
        cout<<s1/g<<"/"<<s2/g<<endl;
    }   
    return 0;
}