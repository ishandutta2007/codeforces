#include<iostream>
using namespace std;

int main()
{
    int n,m,k,i,j,a[101],b[101],re[101],res,nr,x;
    cin >> n >> m >> k;
    for (i=1;i<=m;i++) cin >> a[i];
    for (i=1;i<=k;i++) cin >> b[i];
    res=k+1;
    for (i=1;i<=m;i++)
    {
        x=0;
        for (j=1;j<=k;j++)
           if (b[j]%a[i]==0) x++;
        if (x==res)
        {
          nr++; re[nr]=i;
        }
        if (x<res)
        {
           res=x; nr=1; re[1]=i;
        }
    }
    cout << nr<< endl;
    for (i=1;i<=nr;i++) cout << re[i] << " ";        
 //   system("pause");
    return 0;
}