#include<iostream>
using namespace std;

int main()
{
    int n,k,i,j,np;
    int p[1001];
    bool kt;
    cin >> n >> k;
    np=0;
    for (i=2;i<=n;i++)
    {
        kt=true;
        for (j=1;j<=np;j++)
            if (p[j]*p[j]>i) break;
            else 
            {
                 if (i%p[j]==0) 
                 {
                     kt=false; break;
                 }   
            }
        if (kt)
        {
              np++;
              p[np]=i;
        }
    }
    for (j=1;j<=np;j++)
    {
          n=p[j];
          for (i=1;i<np;i++)
              if (p[i]+p[i+1]+1==n) 
              {
                 k--; break;
              }
          n--;
    }
    if (k>0) cout << "NO";
    else cout << "YES";
    //system("pause");
    return 0;
}