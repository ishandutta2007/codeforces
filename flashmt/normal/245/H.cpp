#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
#define fr(a,b,c) for (int a=b;a<=c;a++)
#define frr(a,b,c) for (int a=b;a>=c;a--)
#define rep(a,b) for (int a=0;a<b;a++)
#define repp(a,b) for (int a=b-1;a>=0;a--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) int(a.size())
#define all(a) a.begin(),a.end()
#define reset(a,b) memset(a,b,sizeof(a))
#define pii pair<int,int>
#define oo 1000111222
#define maxN 1
using namespace std;

int f[5050][5050];
bool isPalin[5050][5050];

int main()
{
	string s;
	int q,l,r,n;
	cin >> s >> q;
	n=sz(s);
	rep(i,n) f[i][i]=1, isPalin[i][i]=isPalin[i+1][i]=1;
	fr(l,2,n)
		fr(i,0,n-l)
		{
			int j=i+l-1;
			isPalin[i][j]=isPalin[i+1][j-1] && (s[i]==s[j]);
			f[i][j]=f[i+1][j]+f[i][j-1]-f[i+1][j-1]+isPalin[i][j];
		}
		
	while (q--)
	{
		scanf("%d%d",&l,&r);
		printf("%d\n",f[--l][--r]);
	}
}