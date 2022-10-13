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
#define pii pair<int,int>
#define oo 1000111222
#define maxN 1
using namespace std;
const int po[]={1,10,100,1000,10000,100000};

int n,a[6],l[100000],b[6][6],fir[100000];
long long ans;
vector <int> p;
map <int,long long> save;

void att(int z)
{
	if (z>n) 
	{
		ans++;
		return;
	}
	int i=fir[a[z]],lim=a[z]+po[n-z+1];
	if (i<0) return;
	
	while (i<sz(p) && p[i]<lim)
	{
		int t=p[i];
		frr(j,n,z+1) a[j]+=t%10*po[n-z], t/=10;
		att(z+1);
		t=p[i++];
		frr(j,n,z+1) a[j]-=t%10*po[n-z], t/=10;
	}
}

void calc()
{
	n=0;
	int t=a[1];
	while (t) n++, t/=10;
	t=a[1];
	fr(i,2,n) a[i]=0;
	frr(i,n,2) a[i]+=t%10*po[n-1], t/=10;	
	att(2);
}

int main()
{
	memset(fir,-1,sizeof(fir));
	int last=0;
	fr(i,2,99999)
	{
		int ok=1;
		for (int j=2;j*j<=i;j++)
			if (i%j==0) 
			{
				ok=0; break;
			}
		if (ok) 
		{
			p.pb(i);
			while (last<=i) fir[last++]=sz(p)-1;
		}
	}
	
	int test;
	cin >> test;
	while (test--)
	{
		ans=0;
		cin >> a[1];
		if (save.count(a[1])) ans=save[a[1]];
		else calc(), save[a[1]]=ans;
		cout << ans << endl;
	}
}