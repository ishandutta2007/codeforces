#include <bits/stdc++.h>
using namespace std;
#define rep(a,b,c) for(int a=b;a<c;++a)
#define repeq(a,b,c) for(int a=b;a<=c;++a)
#define debug(x) cerr<<(#x)<<": "<<x<<endl
typedef long long ll;
const int SZ=300;
int n, m, weight[SZ], lf[SZ], rt[SZ];
double defeat[SZ][SZ], toWin[SZ][SZ], best[SZ][SZ], bestAny[SZ], val[SZ];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	m = 1<<n;
	rep(i,0,m) rep(j,0,m)
	{
		cin >> defeat[i][j];
		defeat[i][j]/=100.0;
	}
	rep(i,0,m)
	{
		lf[i+m]=i, rt[i+m]=i+1;
		toWin[i][i+m]=1;
		best[i][i+m]=0;
		bestAny[i+m]=0;
		val[i+m]=0.5;
	}
	for(int i=m-1;i>0;--i)
	{
		lf[i]=lf[i*2];
		rt[i]=rt[i*2+1];
		int mid = lf[i*2+1];
		rep(j,lf[i],mid)
		{
			double losethis = 0;
			rep(k,mid,rt[i])
			{
				losethis+=defeat[k][j]*toWin[k][2*i+1];
			}
			toWin[j][i] = toWin[j][2*i]*(1-losethis);
		}
		rep(j,mid,rt[i])
		{
			double losethis = 0;
			rep(k,lf[i],mid)
				losethis+=defeat[k][j]*toWin[k][2*i];
			toWin[j][i] = toWin[j][2*i+1]*(1-losethis);
		}
		val[i] = 2*val[2*i];
		bestAny[i] = 0;
		rep(j,lf[i],mid)
		{
			best[j][i] = toWin[j][i]*val[i] + best[j][2*i] + bestAny[2*i+1];
			bestAny[i] = max(bestAny[i],best[j][i]);
		}
		rep(j,mid,rt[i])
		{
			best[j][i] = toWin[j][i]*val[i] + best[j][2*i+1] + bestAny[2*i];
			bestAny[i] = max(bestAny[i],best[j][i]);
		}
	}
	printf("%.14f\n",bestAny[1]);
}