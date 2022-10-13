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

int main()
{
	//freopen("a.in.1","r",stdin);
	int n,m;
	cin >> n >> m;
	while (n--)
	{
		int s,f,t,u,ss,ff;
		scanf("%d%d%d",&s,&f,&t);
		s--; f--;
		if (s==f) { printf("%d\n",t); continue; }
		u=t/(2*m-2)*(2*m-2);
		if (s+u>=t) ss=s+u;
		else
			if (u+2*m-2-s>=t) ss=u+2*m-2-s;
			else ss=u+2*m-2+s;
		u=ss/(2*m-2)*(2*m-2);
		if (f+u>=ss) ff=f+u;
		else
			if (u+2*m-2-f>=ss) ff=u+2*m-2-f;
			else ff=u+2*m-2+f;
		printf("%d\n",ff);
	}
	return 0;
}