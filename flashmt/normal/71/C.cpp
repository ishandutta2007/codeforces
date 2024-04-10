#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<string>
#define fr(a,b,c) for(a=b;a<=c;a++)
#define frr(a,b,c) for(a=b;a>=c;a--)
#define rp(a,b,c) for(a=b;a<c;a++)
#define rpp(a,b,c) for(a=b;a>c;a--)
#define maxn 100010
using namespace std;
typedef long long ll;

int n,re,a[maxn],b[maxn];

int ok(int x)
{
    if (n/x<3) return 0;
    int i;
    fr(i,0,x-1) b[i]=0;
    fr(i,0,n-1) if (a[i]) b[i%x]++;
    fr(i,0,x-1)
      if (b[i]==n/x) return 1;
    return 0;
}

int main()
{
    int i,x=0;
    cin >> n;
    fr(i,0,n-1) 
    {
       scanf("%d",&a[i]);x+=a[i];
    }
    if (x==n) {cout << "YES"<< endl; return 0;}
    fr(i,2,n)
      if (i*i>n) break;
      else 
      {
         if (n%i==0)
         {
             if (ok(i)) {cout <<"YES"<<endl; return 0;}         
             if (ok(n/i)) {cout <<"YES"<< endl; return 0;}
         }
      }
    cout << "NO"<< endl;
    //system("pause");
    return 0;
}