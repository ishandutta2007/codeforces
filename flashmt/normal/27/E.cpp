#include<iostream>
using namespace std;
int n,a[10000],b[10000],m,p[10000],np;
long long re;

void att(int m)
{
     int i,j,k,q;
     long long s=1;
     q=0;
     for (i=m;i>=1;i--)
      if (s<re)
      for (j=1;j<=b[i];j++)
      {
          q++;
          for (k=1;k<a[i];k++) 
          {   
              s*=p[q];
              if (s>=re) break;
          }
          if (s>=re) break;
      }
     if (s<re) re=s;       
     for (i=1;i<=m;i++)
      for (j=i;j<=m;j++)
       if (b[i]>0 && b[j]>0)
       {
          if (i==j && b[i]==1) continue;
          b[i]--; b[j]--;
          q=0;
          for (k=1;k<=m;k++)
            if (a[k]==a[i]*a[j])
            {
               q=k; break;
            }
          if (q) 
          {
              b[q]++; 
              if (a[q]<70) att(m);
          }
          else
          {
              a[m+1]=a[i]*a[j]; b[m+1]=1;
              if (a[m+1]<70) att(m+1);
          }
          if (q) b[q]--;
          else b[m+1]--;
          b[i]++; b[j]++;
       }
}

int main()
{
    int i,j;
    cin >> n;
    m=0; np=0;
    for (i=2;i<=n;i++)
    {
        if (n%i==0)
        {
          m++; a[m]=i;
          while (n%i==0)
          {
             n/=i; b[m]++;
          }
        }
    }
    for (i=2;i<=10000;i++)
    {
        bool kt=true;
        for (int j=2;j*j<=i;j++)
           if (i%j==0)
           {
              kt=false; break;
           }
        if (kt)
        {
          np++; p[np]=i;
        }
    }
    re=1000000000; re*=re; 
    att(m);
    cout << re << endl;
    return 0;
}