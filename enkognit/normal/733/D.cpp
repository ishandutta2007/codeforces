#include <bits/stdc++.h>

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

ll n,m=-1e9,k,l=0,r,i,j,w,x,y=-1,p;
ll q[3];

struct foll
{
 ll fi;
 ll se;
 ll th;
 ll fo;
};
foll a[100001];
bool comp(foll x,foll y)
{
 if (x.fi<y.fi || (x.fi==y.fi && x.se<y.se) || (x.fi==y.fi && x.se==y.se && x.th<y.th)) return true;else return false;
}

int main()
{
  //freopen("division.in","r",stdin);
  //freopen("division.out","w",stdout);
  cin >> n;
  for (i=0;i<n;i++)
  {
   cin >> q[0] >> q[1] >> q[2];
   sort(q,q+3);
   a[i].fi=q[2],a[i].se=q[1],a[i].th=q[0],a[i].fo=i+1;
   //cout << a[i].fo <<" "<<a[i].fi<<" "<<a[i].se<<" "<<a[i].th << "\n";system("pause");
  }
  sort(a,a+n,comp);
  for (i=0;i<n-1;i++)
  {
   if (k<a[i].th) {k=a[i].th;x=a[i].fo;y=-1;}
   if (a[i].fi==a[i+1].fi && a[i].se==a[i+1].se)
   {
    if (k<min(min(a[i].fi,a[i].se),a[i].th+a[i+1].th))
    {
     k=min(min(a[i].fi,a[i].se),a[i].th+a[i+1].th);
     x=a[i].fo,y=a[i+1].fo;
    }
   }
  }
  if (k<a[n-1].th) {k=a[n-1].th;x=a[n-1].fo;y=-1;}
  /*cout << k << "\n";
  for (i=0;i<n;i++) cout << a[i].fo <<" "<<a[i].fi<<" "<<a[i].se<<" "<<a[i].th << "\n";*/
  if (y>0) cout << 2 << "\n" << min(x,y) << " " << max(x,y) << "\n"; else cout << 1 << "\n" << x << "\n";
  return 0;
}