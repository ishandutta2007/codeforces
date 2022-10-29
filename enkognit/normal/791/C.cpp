#include <bits/stdc++.h>
#define ll long long
#define len length()

using namespace std;

int n,m,i,j,k,l,a[100001];
bool t[100001];
string s,s1,s2[10001];

string shifr(int h)
{
 int l=h;
 string gh;
 while (l>0)
 {
  if (l%27!=0)
  gh+=(char)(l%27+96); else gh+='z';
  l-=26;
 }
 gh[0]=gh[0]-32;
 return gh;
}

int main()
{
 //freopen("input.txt","r",stdin);
 //freopen("output.txt","w",stdout);
 cin >> n >> m;
 for (i=1;i<=n;i++)
 a[i]=i;
 getline(cin,s);
 getline(cin,s);
 s+=' ';
 j=1;
 int y=0;
 for (i=0;i<s.len;i++)
  if (s[i]!=' ') s1+=s[i]; else
  {
   if (s1[0]=='N')
   {
    int l=m-2;
    for (int u=j-1;u>=max(1,j-m+1);u--)
     if (s2[u]=="YES") break; else l--;
    a[j+l*(l>0)+1]=a[j];
   }
   y++;
   s2[y]=s1;
   s1="";
   j++;
  }
 for (i=1;i<n;i++) cout << shifr(a[i]) << " ";
 cout << shifr(a[n]) << "\n";
 return 0;
}