#include <iostream>

using namespace std;

int arr[1000][1000]={0};
int sm(int a, int b , int c , int d )
{
    if(a>b && a>c && a>d) return a;
    else if(b>a && b>c && b>d) return b;
    else if(c>a && b<c && c>d) return c;
    else return d;
}
int main()
{
    int n,m,k,s,t,d=0,q,i,j,p=0;
    cin>>n>>m>>k;

    for(q=0;q<k;++q)
    {
       cin>>s>>t;
if (arr[s-1][t-1]==0)
       arr[s-1][t-1]=++p;
else p++;}
    for(i=0;i<n;++i)
    for(j=0;j<m;++j)
        if( arr[i][j]!=0 && arr[i+1][j]!=0 && arr[i][j+1]!=0 && arr[i+1][j+1]!=0)
      { p=sm(arr[i][j],arr[i+1][j],arr[i][j+1],arr[i+1][j+1]);
          d=p<d || d==0?p:d;}

    cout<<d;
    return 0;
}