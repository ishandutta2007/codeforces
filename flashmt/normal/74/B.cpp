#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#define fr(a,b,c) for (a=b;a<=c;a++)
#define oo 1000000
using namespace std;

int n,x,y,d,m,f[222][55],re,b[222];
char a[222];

int calc(int t,int x)
{
    int y=b[t],i,r=0,left,right;
    if (f[t][x]>=0) return f[t][x];
    if (t==m-1)
    {
       f[t][x]=oo; 
       return oo;        
    }
    if (a[t]=='0') 
    {
      fr(i,x-1,x+1)
        if (i && i<=n && i!=b[t] && i!=b[t+1]) 
          r=max(r,calc(t+1,i)+1);          
    }
    else
    {
      fr(i,1,n)
        if (i && i<=n && i!=b[t+1])
          r=max(r,calc(t+1,i)+1);  
    }
    f[t][x]=r;
    return f[t][x];
}

int main()
{
    int i,j;
    scanf("%d%d%d\n",&n,&x,&y);
    scanf("%s",a); 
    scanf("%s\n",a); 
    if (!strcmp(a,"head")) d=-1;
    else d=1;
    scanf("%s\n",a);
    m=strlen(a);
    b[0]=y;
    fr(i,1,m)
    {
       if (b[i-1]+d==0 || b[i-1]+d>n) d=-d;
       b[i]=b[i-1]+d;  
    }
    memset(f,-1,sizeof(f));
    re=calc(0,x);
    if (re>=oo) cout << "Stowaway" << endl;
    else cout << "Controller " << re+1 << endl;
    //system("pause");
    return 0;
}