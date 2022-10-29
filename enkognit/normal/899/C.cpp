#include <bits/stdc++.h>

using namespace std;

int n,m,i,j,k,l,h;vector <int> a;

//map <string,vector<string> > s;

int main()
{
 //freopen("number.in","r",stdin);
 //freopen("number.out","w",stdout);
 cin >> n;
 if (n%2==0)
 {
  int d=0;
  if (n/2%2==1) d=1;
  for (i=1;i<=n/2-d;i++) if (i%2==1) {a.push_back(i);a.push_back(n-i+1);}
  if (d==1) a.push_back(n/2);
  if (d==1) cout << 1 << "\n"; else cout << 0 << "\n";
  cout << a.size() << " ";for (i=0;i<a.size();i++) cout << a[i] << " ";
 } else
 if (n%2==1)
 {
  int d=0;
  if ((n-1)/2%2==1) d=1;
  for (i=2;i<=n/2+1-d;i++) if (i%2==0) {a.push_back(i);a.push_back(n-i+2);}
  if (d==1) a.push_back(n/2+1);
  a.push_back(1);
  if (d==1) cout << 0 << "\n"; else cout << 1 << "\n";
  cout << a.size() << " ";for (i=0;i<a.size();i++) cout << a[i] << " ";
 }
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