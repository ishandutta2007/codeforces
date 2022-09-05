#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<set>
#include<utility>
#include<vector>
using namespace std;
#define ff first
#define ss second
#define push_back pb
#define make_pair mp
#define n(x) num/pow(10,x)
long long num;
int k,n,a[20];
int main()
{
    cin>>num>>k;
    long long tmp=num;
    while(tmp>0)tmp/=10,n++;
    tmp=num;
    for(int i=n;i>0;i--)a[i]=tmp%10,tmp=tmp/10;
    for(int i=1;i<=n;i++)
    {
        int max=0,maxi=0;
        for(int j=i;j<=i+k&&j<=n;j++)if(max<a[j])max=a[j],maxi=j;
        if(max>a[i])
        {
            int j=maxi;
            while(j>i&&k>0)swap(a[j],a[j-1]),j--,k--;
        }
    }
    for(int i=1;i<=n;i++)cout<<a[i];
//  system("pause");
    return 0;
}