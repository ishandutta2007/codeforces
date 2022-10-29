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
#define pu push
#define ld long double
#define pld pair<ld,ld>
#define y1 Enkognit
//#define {cout.flush()} {fflush(stdout)}

using namespace std;

ll n,k,m,i,j,o,z,l,p,ans,x;
//vector <ll> a[100001];
map <ll,map<ll,ll> > a;
string s;
vector <string> ss;

ll binpow(ll p,ll o)
{
 ll l=0,y=1;
 while (l<o)
 {
  if (l>0 && l%2==0 && o/2>=l) l*=2,y*=y; else l++,y*=2;
 }
 return p*y;
}

map <string,ll> g;
map <ll,string> y;

int main()
{
  //freopen("half.in","r",stdin);
  //freopen("half.out","w",stdout);
  //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  ll o=0;
  bool q=0;
  while (1)
  {
   getline(cin,s);
   if (s[0]==92 && s[1]=='b' && s[2]=='e') {q=1;continue;}
   if (!q)
   {
    for (i=0;i<s.size();i++)
    if (s[i]==92 && s.substr(i+1,5)=="cite{")
    {
     ll e=i+6;
     string d="";
     while (s[e]!='}') d+=s[e],e++;
     ss.pb(d);
     o++;
     g[d]=o;
    }
   }else
   {
    j++;
    //cout << s << "\n";
    if (j==o+1) break;
    string f=s.substr(s.find('{')+1,s.find('}')-s.find('{')-1);
    if (j!=g[f]) p=1;
    y[g[f]]=s;
   }
  }
  if (!p) cout << "Correct\n"; else
  if (p)
  {
   cout << "Incorrect\n";
   cout << "\\begin{thebibliography}{99}\n";
   for (i=1;i<=o;i++) cout << y[i] << "\n";
   cout << "\\end{thebibliography}\n";
  }
  //cout << "\n" << l << " " << u << "\n";
 return 0;
}