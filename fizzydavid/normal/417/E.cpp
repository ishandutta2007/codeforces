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
int r[111],c[111];
void make(int *a,int n)
{
    if(n==1)a[1]=1;
    else if(n==2)a[1]=3,a[2]=4;
    else 
    {
        for(int i=2;i<=n;i++)a[i]=2;a[1]=n-2;
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    make(c,n);make(r,m);
    for(int i=1;i<=n;i++){for(int j=1;j<=m;j++)printf("%d ",c[i]*r[j]);puts("");}
//  system("pause");
    return 0;
}