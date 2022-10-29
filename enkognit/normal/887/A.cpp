#include <bits/stdc++.h>

using namespace std;

int k,a[1000],r,i,v,nom,mv,mr,nmr,nmv;
char c;
string s;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> s;
    while (s[0]=='0')
    {
     s.erase(0,1);
    }
    if (s.length()>0)
    {if (s[0]=='1')
    {
     for (i=0;i<s.length();i++)
     {
      if (s[i]=='0') k++;
     }
     if (k>=6) cout << "yes"; else cout << "no";
    } else cout << "no";} else cout << "no";

    return 0;
}