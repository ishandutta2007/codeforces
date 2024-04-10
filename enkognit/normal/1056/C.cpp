#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <string>

/*#define mp make_pair
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
#define y1 Enkognit*/
//#define {cout.flush()} {fflush(stdout)}

using namespace std;

int n,p=0,k,m,i,j,o,l,ans,x,y,a[100001],b[10001];
string s,d;
pair<int,int> c[100001];
map <int,int> t;
vector <int> v;

bool comp(int i,int j)
{
 return a[i]>a[j];
}

int main()
{
  //freopen("H.in","r",stdin);
  //freopen("H.out","w",stdout);
  //ios_base::sync_with_stdio(0);cin.tie(0);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  cin >> n >> m;
  fflush(stdout);
  int h=n*2;
  for (i=1;i<=2*n;i++) {cin >> a[i];b[i]=i;fflush(stdout);}
  sort(b+1,b+2*n+1,comp);
  for (i=0;i<m;i++)
  {
   cin >> c[i].first >> c[i].second;
   fflush(stdout);
   x=c[i].first;
   y=c[i].second;
   t[x]=y;
   t[y]=x;
  }
  cin >> p;
  fflush(stdout);
  if (p==2)
  {
   while (h>0)
   {
    int x=0;
    cin >> x;
    if (x==-1) exit(0);
    fflush(stdout);
    h--;
    if (h==0) exit(0);
    a[x]=-1e9;
    if (t[x]!=0) {cout << t[x] << endl;fflush(stdout);a[t[x]]=-1e9;h--;}else break;
   }
  }
  if (h==0) exit(0);
  for (i=0;i<m;i++)
   if (a[c[i].first]>-1e9 && a[c[i].second]>-1e9)
  {
   int x=c[i].first,y=c[i].second;
   //cout << a[x] << " " << a[y] << "\n";
   if (a[x]<a[y]) swap(x,y);
   cout << x << endl;
   fflush(stdout);
   h--;
   if (h==0) exit(0);
   cin >> y;
   if (y==-1) exit(0);
    fflush(stdout);
   a[x]=-1e9;
   a[y]=-1e9;
   h--;
  }
  sort(b+1,b+1+2*n,comp);
  i=1;
  while (h>0 && i<=2*n)
  {
   if (a[b[i]]==-1e9) {i++;continue;}
   cout << b[i] << endl;
   fflush(stdout);
   h--;
   if (h==0) break;
   a[b[i]]=-1e9;
   cin >> o;
   if (o==-1) exit(0);
   fflush(stdout);
   a[o]=-1e9;
   h--;
   i++;
  }
  cout.flush();
  return 0;
}