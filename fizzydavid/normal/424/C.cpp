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
#define ff first
#define ss second
int n,sum,f[1111111];
inline int cmxor(int n,int p)
{
    if((n/p)&1)return f[p-1]^f[n%p];
    else return f[n%p];
}
int main()
{
    scanf("%d",&n);for(int i=1;i<=n;i++)f[i]=f[i-1]^i;
    for(int i=1;i<=n;i++)
    {
        int x;scanf("%d",&x);
        sum=sum^x^cmxor(n,i);
    }
    cout<<sum;
//  system("pause");
    return 0;
}