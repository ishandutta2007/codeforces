#include <iostream>
#include <cstring>

using namespace std;

string s1,s2;
int n,v,m,i,j,k,l,kol1s1,kol1s2;

int main()
{
  cin >> s1;
  cin >> s2;
  for (i=0;i<s1.length();i++) if (s1[i]=='1') k++;
  for (i=0;i<s2.length();i++) if (s2[i]=='1') l++;
  if (k%2==1) k++;
  if (l<=k) cout << "YES"; else cout << "NO";
  return 0;
}