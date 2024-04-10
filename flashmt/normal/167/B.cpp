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

int n,least,bag,prob[222],type[222];
double fBag[222][222][222],fPrize[222][222];
vector < pii > bagTour;
vector <int> prizeTour;

int main()
{
	cin >> n >> least >> bag;
	fr(i,1,n) cin >> prob[i];
	fr(i,1,n) cin >> type[i];
	fr(i,1,n)
		if (type[i]<0) prizeTour.pb(prob[i]);
		else bagTour.pb(mp(prob[i],type[i]));
	int A=sz(prizeTour),B=sz(bagTour);

	fPrize[0][0]=1;
	rep(i,A)
		fr(j,0,i)
		{
			fPrize[i+1][j+1]+=fPrize[i][j]*0.01*prizeTour[i];
			fPrize[i+1][j]+=fPrize[i][j]*0.01*(100-prizeTour[i]);
		}
		
	fBag[0][0][min(bag,n)]=1;
	rep(i,B)
		fr(j,0,i)
			fr(k,0,n)
			{
				fBag[i+1][j+1][min(n,k+bagTour[i].se)]+=fBag[i][j][k]*0.01*bagTour[i].fi;
				fBag[i+1][j][k]+=fBag[i][j][k]*0.01*(100-bagTour[i].fi);
			}
		
	double ans=0;
	fr(i,0,A)
		fr(j,0,B)
			if (i+j>=least)
				fr(k,i,n)
					ans+=fPrize[A][i]*fBag[B][j][k];
					
	printf("%.9lf\n",ans);
}