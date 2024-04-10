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
#define pb push_back 
#define mp make_pair
int main()
{
    int n,k;scanf("%d%d",&n,&k);
    if(n<=k*2)printf("-1");
    else
    {
        printf("%d\n",n*k);
        for(int i=1;i<=k;i++)
        {
            for(int j=1;j<=n;j++)
            {
                printf("%d %d\n",j,(i+j-1)%n+1);
            }
        }
    }
//  system("pause");
    return 0;
}