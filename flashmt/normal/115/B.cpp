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
#define fr(a,b,c) for (a=b;a<=c;a++)
#define frr(a,b,c) for (a=b;a>=c;a--)
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

int m,n,l[155],r[155],re;
string s;

int main()
{
	//freopen("b.in.4","r",stdin);
	int i,j,x=0,lowest=0;
	cin >> m >> n;
	fr(i,0,m-1) 
	{
		cin >> s;
		l[i]=n; r[i]=-1;
		fr(j,0,n-1)
			if (s[j]=='W')
			{
				l[i]=min(l[i],j);
				r[i]=max(r[i],j);
				lowest=i;
			}
	}
	fr(i,0,m-1)
		if (i&1)
		{
			if (l[i]<n)
			{
				re+=x-l[i];
				x=l[i];
			}
			if (i<m-1 && l[i+1]<x)
			{
				re+=x-l[i+1];
				x=l[i+1];
			}
		}
		else
		{
			if (r[i]>=0)
			{
				re+=r[i]-x;
				x=r[i];
			}
			if (i<m-1 && r[i+1]>x)
			{
				re+=r[i+1]-x;
				x=r[i+1];
			}
		}
	cout << re+lowest << endl;
	return 0;
}