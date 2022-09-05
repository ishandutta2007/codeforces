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
    int n,m;scanf("%d%d",&n,&m);
    if(n>m+1||m>(n+1)*2)printf("-1");
    else
    {
        if(n==m+1)
        {
            for(int i=1;i<=m;i++)printf("01");printf("0");
        }
        else if(m>n*2)
        {
            for(int i=1;i<=n;i++)printf("110");
            for(int i=1;i<=m-n*2;i++)printf("1");
        }
        else
        {
            for(int i=1;i<=m-n;i++)printf("110");
            for(int i=1;i<=2*n-m;i++)printf("10");
        }
    }
//  system("pause");
    return 0;
}