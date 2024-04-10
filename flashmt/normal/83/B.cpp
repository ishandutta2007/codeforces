#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<vector>
#include<utility>
#include<set>
#include<sstream>
#define fr(a,b,c) for (a=b;a<=c;a++)
#define frr(a,b,c) for (a=b;a>=c;a--)
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define oo 1000111222
using namespace std;
typedef long long ll;

int n,d[100100];
long long s,sum=0;
vector < pii > a,b,c;

int main()
{
   int i,x,j,t,u,cnt,cur;
   long long tt;
   cin >> n >> s;
   a.clear(); b.clear(); c.clear();
   fr(i,0,n-1) scanf("%d",&x), sum+=x, a.pb(mp(x,i)), d[i]=x;
   sort(a.begin(),a.end());
   cnt=n;
   if (sum<s) cout << "-1" << endl;
   else
    if (sum==s) cout << endl;
    else
    {
         cur=1; 
         fr(i,1,n-1)
            if (a[i].first!=a[i-1].first) 
            {
               b.pb(mp(a[i-1].first,cnt)); cnt-=cur; cur=1;
            }
            else cur++;
         b.pb(mp(a[n-1].first,cnt));
         //fr(i,0,b.size()-1) cout << b[i].first << " "<< b[i].second <<endl;
         frr(i,int(b.size())-1,1) b[i].first-=b[i-1].first;
         fr(i,0,int(b.size())-1) 
            if (1LL*b[i].first*b[i].second>=s) break;
            else s-=1LL*b[i].first*b[i].second;
         //cout << s << " " << i << endl;
         tt=s/b[i].second;
         s%=b[i].second;
         t=0; u=b[i].second;
         fr(j,0,i-1) t+=b[j].first; 
         fr(i,0,n-1)
           if (d[i]>t) c.push_back(mp(i,d[i]-int(tt)-t));
         //fr(i,0,c.size()-1) cout << c[i].first<<" "<<c[i].second<< endl;
         fr(i,0,s-1) c[i].second--;
         i=s; 
         fr(j,0,u-1)
         {
            if (i==c.size()) i=0;
            if (c[i].second) printf("%d ",c[i].first+1);
            ++i;
         }
         cout << endl;
    }
   return 0;
}