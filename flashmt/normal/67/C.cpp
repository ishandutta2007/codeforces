#include<iostream>
#include<algorithm>
#include<string>
#include<cstdio>
#include<cstring>
#define oo 1000000000
#define fr(a,b,c) for(a=b;a<=c;a++)
using namespace std;

int td,ti,te,tr,m,n,pa[4444][26],pb[4444][26],a[4444],b[4444],cur[26],f[4444][4444];
char s[4444];

int main()
{
    int i,j;
    scanf("%d%d%d%d\n",&ti,&td,&tr,&te);
    gets(s);
    m=strlen(s);
    fr(i,0,m-1) 
    {
       a[i+1]=int(s[i])-97;          
       fr(j,0,25) pa[i+1][j]=cur[j];
       cur[a[i+1]]=i+1;
    }
    fr(i,0,25) cur[i]=0;
    gets(s);
    n=strlen(s);
    fr(i,0,n-1)
    {
       b[i+1]=int(s[i])-97;
       fr(j,0,25) pb[i+1][j]=cur[j];
       cur[b[i+1]]=i+1;
    }
    fr(i,0,m)
     fr(j,0,n)
     {
        if (!(i+j)) continue;
        int ff=oo;
        if (j) ff=min(ff,f[i][j-1]+ti);
        if (i) ff=min(ff,f[i-1][j]+td);
        if (i && j) ff=min(ff,f[i-1][j-1]+int(a[i]!=b[j])*tr);
        int ii=pa[i][b[j]],jj=pb[j][a[i]];
        if (ii && jj) ff=min(ff,f[ii-1][jj-1]+td*(i-ii-1)+ti*(j-jj-1)+te);
        f[i][j]=ff;
     }
    cout << f[m][n] << endl;
    //system("pause");
    return 0;
}