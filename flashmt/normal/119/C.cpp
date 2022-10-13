#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <sstream>
#define fr(a,b,c) for (int a=b;a<=c;a++)
#define frr(a,b,c) for (int a=b;a>=c;a--)
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define F first
#define S second
#define oo 1000111222
using namespace std;
typedef long long ll;
const int dx[]={-1,0,1,0,-1,1,1,-1};
      int dy[]={0,1,0,-1,1,1,-1,-1};
struct subject
{
	int c,d,pos;
	long long a,b;
};

int n,m,k;
long long f[55][55][111];
subject s[55];
vector < pair<int,long long> > re;

bool cmp(subject i,subject j) { return i.c<j.c; }

void trace(int i,int j,int p)
{
	re.push_back(make_pair(s[i].pos,s[i].a+p));
	if (j==1) 
	{
		frr(i,n-1,0) cout << re[i].first << " " << re[i].second << endl;
		exit(0);
	}
	long long x=s[i].a+p;
	fr(ii,1,i-1)
	 if (s[ii].c<s[i].c)
		{
			int z=int(x-k-s[ii].a);
			if (z>=0 && z<=s[ii].d && f[ii][j-1][z]+x==f[i][j][p]) trace(ii,j-1,z);
			if (x%(1LL*k)==0)
			{
				int z=int(x/k-s[ii].a);
				if (z>=0 && z<=s[ii].d && f[ii][j-1][z]+x==f[i][j][p]) trace(ii,j-1,z);
			}
		}
}

int main()
{
	//freopen("c2","r",stdin);
	cin >> n >> m >> k;
	fr(i,1,m) cin >> s[i].a >> s[i].b >> s[i].c, s[i].d=s[i].b-s[i].a, s[i].pos=i;
	sort(s+1,s+m+1,cmp); 
	fr(i,1,m)
	 fr(j,1,min(n,i))
	  fr(p,0,s[i].d)
	   if (j==1 || i==1) f[i][j][p]=s[i].a+p;
	   else 
	    fr(ii,1,i-1)
				if (s[ii].c<s[i].c)
		    {
				  long long x=s[i].a+p;
				  int z=int(x-k-s[ii].a);
				  if (z>=0 && z<=s[ii].d && f[ii][j-1][z]) f[i][j][p]=max(f[i][j][p],f[ii][j-1][z]+x);
				  if (x%(1LL*k)==0)
				  {
					  z=int(x/k-s[ii].a);
					  if (z>=0 && z<=s[ii].d && f[ii][j-1][z]) f[i][j][p]=max(f[i][j][p],f[ii][j-1][z]+x);
				  }
			  }
	long long re=0;
	fr(i,1,m)
	 fr(p,0,s[i].d)
	  re=max(re,f[i][n][p]);
	if (re==0) puts("NO");
	else
	  fr(i,1,m)
	   fr(p,0,s[i].d)
	    if (f[i][n][p]==re)
	    {
				puts("YES"); trace(i,n,p);
			}
	return 0;
}