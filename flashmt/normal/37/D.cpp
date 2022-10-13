#include<iostream>
#include<algorithm>
#include<cmath>
#define fr(a,b,c) for (a=b;a<=c;a++)
#define z 1000000007
#define maxs 1010
using namespace std;

int n,a[111],b[111],s,c[maxs][111];
long long f[111][maxs];

int main()
{
    int i,j,k;
    cin >> n;
    fr(i,1,n) 
    {
       cin >> a[i]; s+=a[i];
    }
    fr(i,1,n) cin >> b[i];
    fr(i,0,s)
    {
       c[i][0]=1; c[i][i]=1;
       fr(j,1,min(i-1,100)) 
       {
          c[i][j]=c[i-1][j]+c[i-1][j-1];
          if (c[i][j]>=z) c[i][j]-=z;
       }
    }
    fr(j,0,a[1]) f[1][j]=c[a[1]][j];
    s=a[1];
    fr(i,2,n)
    {
        fr(j,0,b[i])
          fr(k,0,s)
            f[i][j+k]=(f[i][j+k]+f[i-1][k]*c[s+a[i]-k][j])%z;
        s+=a[i];       
    }
    long long re=f[n][s];
    fr(i,1,n) 
    {
       re=(re*c[s][a[i]])%z;
       s-=a[i];
    }
    cout << re << endl;
//    system("pause");
    return 0;
}