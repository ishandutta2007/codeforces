#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    long long k,n,m,i,j,g=0,l=0,h=0;
    string s;
    cin >> n;
    cin >> s;
    s=' '+s;
    k=0;
    l=n;
    for (i=1;i<=n;i++)
    {
     if (s[i]=='L')
     {
      if (h==0) l-=i-k;
      else
      {
       l-=i-k+1;
       if ((i-k+1)%2==1) l++;
      }
      k=i;
     }else
     if (s[i]=='R') {k=i;h=1;}
    }
    if (s[k]=='R') l-=n-k+1;
    cout << l;
    return 0;
}