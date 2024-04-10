#include <bits/stdc++.h>

using namespace std;

int n,m,i,j,k,l;
string s,s11,s21,s12,s22;

int main()
{
 //freopen("input.txt","r",stdin);
 //freopen("output.txt","w",stdout);
 getline(cin,s11);
 getline(cin,s21);
 s12=s11;
 s22=s21;
 for (i=0;i<s11.length();i++)
 {
  if (islower(s11[i])) s12[i]=s11[i]-32; else s12[i]=s11[i];
  if (isupper(s11[i])) s11[i]=s11[i]+32;
  if (islower(s21[i])) s22[i]=s21[i]-32; else s22[i]=s11[i];
  if (isupper(s21[i])) s21[i]=s21[i]+32;
 }
 getline(cin,s);
 for (i=0;i<s.length();i++)
  if (isalpha(s[i]))
 {
  if (islower(s[i])) cout << s21[s11.find(s[i])]; else
  cout << s22[s12.find(s[i])];
 } else cout << s[i];
 return 0;
}