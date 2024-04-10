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

string a[111],s,t;
char lucky;
int n,i,d[111];

int main()
{
	//freopen("a.in.0","r",stdin);
	cin >> n;
	fr(i,1,n) 
	{
		cin >> a[i];
		for (int j=0;j<int(a[i].length());j++)
			if (a[i][j]>='a') a[i][j]-=32;
	}
	cin >> s;
	t=s;
	cin >> lucky;
	if (lucky>='a') lucky-=32;
	int sl=s.length();
	for (int j=0;j<sl;j++)
		if (s[j]>='a') s[j]-=32, d[j]=1;
	for (int i=0;i<sl;i++)
	{
		for (int j=1;j<=n;j++)
		{
			int l=a[j].length();
			if (i+l<=sl && s.substr(i,l)==a[j])
				for (int k=0;k<l;k++) 
					if (s[i+k]==lucky)
					{
						if (lucky=='A') t[i+k]=(d[i+k]?'b':'B');
						else t[i+k]=(d[i+k]?'a':'A');
					}
					else t[i+k]=(d[i+k]?lucky+32:lucky);
		}
	}
	cout << t << endl;
	return 0;
}