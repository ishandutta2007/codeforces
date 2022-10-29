#include <bits/stdc++.h>

using namespace std;

int n,m,i,j,k,l,h,a[1000001];
//map <string,vector<string> > s;
set <int> g;
//string s1,s2,s3[3000];

int main()
{
 //freopen("number.in","r",stdin);
 //freopen("number.out","w",stdout);
 cin >> n;
 for (i=1;i<=n;i++)
 {
  cin >> l;
  m+=(l==2);
  k+=(l==1);
 }
 if (m>=k) cout << k; else
 if (m<k) cout << m+(k-m)/3;
 return 0;
}
/*cin >> n;
 for (i=1;i<=n;i++)
 {
  cin >> s1;
  if (s[s1].size()==0) {h++;s3[h]=s1;}
  cin >> l;
  for (j=1;j<=l;j++)
  {
   cin >> s2;
   s[s1].push_back(s2);
  }
 }

 for (i=1;i<=h;i++)
 {
  a[i]=s[s3[i]].size();
  for (j=0;j<s[s3[i]].size();j++)
   for (int u=0;u<s[s3[i]].size();u++)
    if (u!=j && s[s3[i]][j]!="a" && s[s3[i]][j]!="a" && s[s3[i]][j].find(s[s3[i]][u])==s[s3[i]][j].length()-s[s3[i]][u].length() &&
        s[s3[i]][j].length()>=s[s3[i]][u].length()) {s[s3[i]][u]="a";a[i]--;}
 }
 cout << h << "\n";
 for (i=1;i<=h;i++)
 {
  cout << s3[i] << " ";
  cout << a[i] << " ";
  string u;
  for (auto u : s[s3[i]])
   if (u!="a")cout << u << " ";
  cout << endl;
 }*/

/* cin >> n;
    cin >> a[1];
    k=1;
    for (i=1;i<=a[1];i++) s2+='a';
    for (i=2;i<=n;i++)
    {
     cin >> a[i];
     if (a[i]>a[i-1]) s1=s2+'a'; else
     if (a[i]<=a[i-1])
     {
      char c='z';
      int h;
      for (j=0;j<a[i];j++)
      {
       s1+=s2[j];
       if (s2[j]<=c) {c=s2[j];h=j;}
      }
      s1[h]++;
      k=max(c-95,k);
     }
     s2=s1;s1="";
    }
    cout << k << endl;
    return 0;*/