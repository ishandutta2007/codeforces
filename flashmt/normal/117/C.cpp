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

char a[5050][5050];
int n;
vector <int> b;

int main()
{
	cin >> n;
	for (int i=0;i<n;i++) scanf("%s",&a[i]);
	b.pb(1);
	for (int i=2;i<=n;i++)
	{
		int win,lose;
		fr(win,0,i-2)
			if (a[i-1][b[win]-1]=='1') break;
		frr(lose,i-2,0)
			if (a[i-1][b[lose]-1]=='0') break;
		if (win!=lose+1) 
		{
			cout << b[win] << " " << b[lose] << " " << i << endl;
			return 0;
		}
		else 
			if (win<=i-2) b.insert(b.begin()+win,i);
			else b.pb(i);
	}
	puts("-1");
	return 0;
}