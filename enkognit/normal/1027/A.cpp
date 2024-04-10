#include <bits/stdc++.h>
#include <string>

#define mp make_pair
#define ll long long
#define fi first
#define se second
#define fr front()
#define pb push_back
#define len length()
#define sqr(a) ((a)*(a))
#define pll pair<ll,ll>

using namespace std;

//struct thll{ll fi,se,th;};

int main()
{
  //freopen("msched.in","r",stdin);
  //freopen("msched.out","w",stdout);
  int n;
  cin >> n;
  for (int j=0;j<n;j++)
  {
   string s;int m;bool tt=0;
   cin >> m;
   cin >> s;
   for (int i=0;i<m/2;i++)
    if (s[i]!=s[m-i-1] && s[i]+1!=s[m-i-1]-1 && s[i]-1!=s[m-i-1]+1) {tt=1;cout << "NO\n";break;}
   if (!tt) cout << "YES\n";
  }
  //system("pause");
  return 0;
}