#include <bits/stdc++.h>

using namespace std;
long h,w,a[500][500]={0},b[500][500]={0},i,j,u=0,r=0,q,ww[100000][4],s,y=0,t=0;
int main()
{
    char x[501][501];
    cin>>h>>w;
    for(i=0;i<h;++i)
        for(j=0;j<w;++j)
        cin>>x[i][j];
    for(i=0;i<h;++i)
    {   r=0;y=0;
        for(j=0;j<w;++j)
    {
        if(x[i][j]=='.')
        {r++;
        a[i][j]=y+r-1;}
        else {y+=r-1+!r;a[i][j]=y;r=0;}
    }
    }
     for(i=0;i<w;++i)
    {   u=0;t=0;
        for(j=0;j<h;++j)
    {
        if(x[j][i]=='.')
        {u++;
        b[j][i]=t+u-1;}
        else {t+=u-1+!u;b[j][i]=t;u=0;}
    }
    }
    cin>>q;
    for(i=0;i<q;++i)
    {  for(j=0;j<4;++j)
        cin>>ww[i][j];
    }
    for(i=0;i<q;++i)
    {
       s=0;
       for(j=ww[i][0]-1;j<ww[i][2];++j)
       {
           s+=a[j][ww[i][3]-1]-a[j][ww[i][1]-1];
       }
       for(j=ww[i][1]-1;j<ww[i][3];++j)
       {
           s+=b[ww[i][2]-1][j]-b[ww[i][0]-1][j];
       }
       cout<<s<<endl;
    }
    return 0;
}