#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <utility>
#include <cstring>
#define fr(a,b,c) for (a=b;a<=c;a++)
#define frr(a,b,c) for (a=b;a>=c;a--)
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define F first
#define S second
#define maxN 100100
using namespace std;
typedef long long ll;

vector < pii > q;
vector <int> X;
vector <int>::iterator it;
int Q,s[maxN*5];
ll f[maxN*5][5];

void Update(int nd,int l,int r,int x)
{
	if (l==r) 
	{
		if (s[nd]) s[nd]=f[nd][0]=0;
		else s[nd]=1, f[nd][0]=X[x];
	}
	else
	{
		int i,m=(l+r)/2;
		if (x<=m) Update(nd*2,l,m,x);
		else Update(nd*2+1,m+1,r,x);
		fr(i,0,4) f[nd][i]=f[nd*2][i]+f[nd*2+1][(i+5-s[nd*2])%5];
		s[nd]=(s[nd*2]+s[nd*2+1])%5;
		//cout << "node " << nd << " left " << l << " right " << r << " : ";
		//fr(i,0,4) cout << f[nd][i] << " "; cout << " s " << s[nd] << " " << x << endl;
	}
}

int main()
{
	//freopen("d.in","r",stdin);
	int i,x;
	char s[11];
	cin >> Q;
	fr(i,0,Q-1)
	{
		scanf("%s",&s); 
		if (s[0]=='s') q.pb(mp(0,0));
		else
		{
			scanf("%d",&x);
			if (s[0]=='a') q.pb(mp(1,x));
			else q.pb(mp(-1,x));
			X.pb(x);
		}
	}
	sort(X.begin(),X.end());
	it=unique(X.begin(),X.end());
	X.resize(it-X.begin());
	fr(i,0,Q-1)
		if (q[i].F)
		{ 
			x=lower_bound(X.begin(),X.end(),q[i].S)-X.begin();
			Update(1,0,int(X.size())-1,x);
		}
		else printf("%lld\n",f[1][2]);
  return 0;
}