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
#define ll long long
ll n,x[111111],a,b;
int main()
{
    scanf("%d %d %d",&n,&a,&b);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x[i]);
        printf("%d ",x[i]*a%b/a);
    }
    return 0;
}