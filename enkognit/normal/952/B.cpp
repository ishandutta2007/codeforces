#include <bits/stdc++.h>

#define ll long long
#define pb push_back()

using namespace std;

//int a[5001],c[5001],d[5001];

ll n,m,i,j,k,l;
vector <ll> a(11);
string s;

int main()
{
   //freopen("input.txt","r",stdin);
   //freopen("output.txt","w",stdout);
   for (i=0;i<=9;i++)
   {
    cout << i << "\n";
    getline(cin,s);
    while (s[0]==' ') s.erase(0,1);
    while (s[s.length()-1]==' ') s.erase(s.length()-1,1);
    if (s=="no") l++; else
    if (s=="cool" || s=="not bad" || s=="great!" ||
        s=="dont touch me!" || s=="dont think so") {cout <<"normal";return 0;}  else
    if (s=="go die in a hole" || s=="worse" || s=="terrible" || s=="no way" ||
        s=="are you serious?"){cout <<"grumpy";return 0;}
    if (l>3) {cout << "normal";return 0;}
   }
   return 0;
}