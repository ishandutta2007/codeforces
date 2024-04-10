#include<iostream>
#include<algorithm>
#include<cstdio>
#define fr(a,b,c) for (a=b;a<=c;a++)
#define frr(a,b,c) for (a=b;a>=c;a--)
using namespace std;

int n,i,j,a[1111],m=0,re[1111],d[1111];

int main()
{
    char c;
    scanf("%d\n",&n);
    a[0]=0;
    fr(i,1,n-1)
    {
        scanf("%c",&c);
        if (c=='=') d[m]++;
        if (c=='L') a[++m]=-1; 
        if (c=='R') a[++m]=1; 
    }
    if (!m)
    {
        fr(i,1,n) cout << 1 << " ";
        cout << endl;
//        system("pause");
        return 0;   
    }
    a[m+1]=1; a[0]=-1;
    fr(i,1,m)
      if (a[i]<0 && a[i+1]>0) 
      {
          re[i+1]=1;
          frr(j,i,1)
            if (a[j]<0) re[j]=re[j+1]+1;
            else break;
      }     
    frr(i,m,1)
      if (a[i]>0 && a[i-1]<0)
      {
          re[i]=1;
          fr(j,i,m)
            if (a[j]>0) re[j+1]=re[j]+1;
            else break;       
      }  
    fr(i,1,m-1)
      if (a[i]>0 && a[i+1]<0) re[i+1]=max(re[i],re[i+2])+1;
    fr(i,1,m+1)
      fr(j,0,d[i-1])
        cout << re[i] << " ";
    cout << endl;
 //   system("pause");
    return 0;
}