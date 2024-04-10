#include <bits/stdc++.h>

#define ll long long
#define pb push_back()
#define sqr(a) ((a)*(a))

using namespace std;

ll n,m,k,l,i,j;
string s;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> s;
    if (s.find("ABC")!=-1 || s.find("ACB")!=-1 || s.find("BAC")!=-1 || s.find("BCA")!=-1
        || s.find("CAB")!=-1 || s.find("CBA")!=-1) cout << "Yes"; else cout << "No";
    return 0;
}
/*cin >> n >> m;
    cin >> s;
    s=' '+s;
    for (i=1;i<=s.length();i++)
     if (s[i]=='.')
     {
      if (i<=m || n-i<m) s[i]=0; else
      if (i>m && n-i>=m)
      {
       if ((rec(i+m)!='2') && rec(i+m)!=a[i-m]) {cout << "No";exit(0);} else
       if (a[i-m]=='1') a[i]='0'; else a[i]='1';
      } else
      if (n-i>=m)
      {
       if (rec(i+m)=='2') a[i]='0'; else
       if (rec(i+m)=='1') a[i]='0'; else a[i]='1';
      }
     }    */