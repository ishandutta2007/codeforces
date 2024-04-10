#include <bits/stdc++.h>

#define mp make_pair
#define ll long long
#define fi first
#define se second
#define fr front()
#define pb push_back
#define len length()
#define pll pair<ll,ll>
#define sqr(a) ((a)*(a))

using namespace std;

ll n,m,i,j,l=1e9,r,o,k=0;pll x,y;map <char,ll> a;char ch;map<char,bool> t;
string s;

int main()
{
  //freopen("rvq.in","r",stdin);
  //freopen("rvq.out","w",stdout);
  ios_base::sync_with_stdio(0);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  cin >> n;
  for (j=0;j<n;j++)
  {
   vector <ll> l,r,c;
   cin >> s;
   if (s.size()<3) {cout << 0;continue;}
   for (i=0;i<s.size();i++)
    if (islower(s[i])) l.pb(i); else
    if (isupper(s[i])) r.pb(i); else
    c.pb(i);
   if (l.size()==0)
   {
    if (c.size()>1 && r.size()>0)s[c[0]]='a';else
    if (c.size()>0 && r.size()>1)s[r[0]]='a';else
    if (c.size()>1 && r.size()==0)
    {
     ll q=1e9,w=0,e=0;
     for (int u=0;u<c.size()-1;u++) if (c[u+1]-c[u]<q) q=c[u+1]-c[u],w=c[u],e=c[u+1];
     s[w]='a';
     s[e]='A';
    }else
    if (c.size()==0 && r.size()>1)
    {
     ll q=1e9,w=0,e=0;
     for (int u=0;u<r.size()-1;u++) if (r[u+1]-r[u]<q) q=r[u+1]-r[u],w=r[u],e=r[u+1];
     s[w]='a';
     s[e]='1';
    }
   }else
   if (c.size()==0)
   {
    if (l.size()>1 && r.size()>0)s[l[0]]='1';else
    if (l.size()>0 && r.size()>1)s[r[0]]='1';else
    if (l.size()>1 && r.size()==0)
    {
     ll q=1e9,w=0,e=0;
     for (int u=0;u<l.size()-1;u++) if (l[u+1]-l[u]<q) q=l[u+1]-l[u],w=l[u],e=l[u+1];
     s[w]='1';
     s[e]='A';
    }else
    if (l.size()==0 && r.size()>1)
    {
     ll q=1e9,w=0,e=0;
     for (int u=0;u<r.size()-1;u++) if (r[u+1]-r[u]<q) q=r[u+1]-r[u],w=r[u],e=r[u+1];
     s[w]='a';
     s[e]='1';
    }
   }else
   if (r.size()==0)
   {
    if (l.size()>1 && c.size()>0)s[l[0]]='A';else
    if (l.size()>0 && c.size()>1)s[c[0]]='A';else
    if (l.size()>1 && c.size()==0)
    {
     ll q=1e9,w=0,e=0;
     for (int u=0;u<l.size()-1;u++) if (l[u+1]-l[u]<q) q=l[u+1]-l[u],w=l[u],e=l[u+1];
     s[w]='1';
     s[e]='A';
    }else
    if (l.size()==0 && c.size()>1)
    {
     ll q=1e9,w=0,e=0;
     for (int u=0;u<c.size()-1;u++) if (c[u+1]-c[u]<q) q=c[u+1]-c[u],w=c[u],e=c[u+1];
     s[w]='a';
     s[e]='A';
    }
   }
   cout << s << "\n";
  }
  return 0;
}
/**/