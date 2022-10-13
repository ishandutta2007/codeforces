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

int f[5555][5555],n,h[5555],sh[5555];

int main()
{
	cin >> n;
	fr(i,1,n) scanf("%d",h+i), sh[i]=sh[i-1]+h[i];
	
	fr(i,1,n)
	{
		int H=sh[i],HH=0,k=1;
		f[i][0]=i-1; f[i][i]=oo;
		fr(j,1,i-1)
		{
			H-=h[j];
			HH+=h[j];
			while (HH>H) HH-=h[k++];
			f[i][j]=min(oo,f[j][k-1]+i-j-1);
		}
		repp(j,i) f[i][j]=min(f[i][j],f[i][j+1]);
	}
	
	cout << f[n][0] << endl;
}