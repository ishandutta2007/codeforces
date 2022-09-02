#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
typedef long long ll;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)

int type[105],num[105],n;
map<char,int>ma;
int mask[5];
int mask2[5];
int main()
{
	ma['R']=0;
	ma['B']=1;
	ma['G']=2;
	ma['Y']=3;
	ma['W']=4;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		string x;
		cin >> x;
		type[i] = ma[x[0]];
		num[i] = x[1]-'0';
		mask[num[i]] |= (1<<type[i]);
		mask2[type[i]+1] |= (1<<(num[i]-1));
	}
	int ret = INF;
	//
	for(int i=0;i<32;i++)
	{
		for(int j=0;j<32;j++)
		{
			vector<int>ot; ot.clear();
			int all = 0;
			for(int k=0;k<5;k++)
			{
				if(((i>>k)&1))
				{
					int f = mask2[k+1] - (mask2[k+1] & j);
					if(f!=0 && f!=1 && f!=2 && f!=4 && f!=8 && f!=16) goto out;
				}
				else
				{
					int f = mask2[k+1] - (mask2[k+1] & j);
					if(f!=0 && f!=1 && f!=2 && f!=4 && f!=8 && f!=16) goto out;
					all |= f;
					ot.pb(mask2[k+1]);
				}
			}
			for(int k=0;k<ot.size();k++) for(int l=k+1;l<ot.size();l++) if((ot[k]&ot[l])>0) goto out;
			if(all!=0 && all!=1 && all!=2 && all!=4 && all!=8 && all!=16) goto out;
			ret = min(ret,__builtin_popcount(i)+__builtin_popcount(j));
			out:;
		}
	}
	cout << ret << endl;
}