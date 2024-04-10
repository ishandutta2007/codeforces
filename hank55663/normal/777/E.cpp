#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<string.h>
#include<stack> 
#include<set>
#include<map>
#include<iostream>
#include <iomanip>
#include<assert.h>
#include<bits/stdc++.h>
//#define Min(a,b,c) min((a),min((b),(c)))
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-11
#define N 500005
#define pi 3.14159265359
typedef long long LL;
using namespace std;
const int mod = 1e9+7;
struct ring{
	int a,b,h;
};
bool operator<(const ring &a,const ring &b){
	if(a.b!=b.b)
	return a.b>b.b;
	return a.a>b.a;
}
int main(){
	int n;
	scanf("%d",&n);
	ring r[N];
	for(int i=0;i<n;i++)
	scanf("%d %d %d",&r[i].a,&r[i].b,&r[i].h);
	sort(r,r+n);
	LL dp[N];
	map<int,LL> m;
	m.clear();
	dp[0]=r[0].h;
	m[r[0].a]=dp[0];
	LL ans=dp[0];
	m[0]=0;
	for(int i=1;i<n;i++)
	{
		map<int,LL>::iterator it=m.lower_bound(r[i].b);
		//printf("%d %d %d\n",it->x,it->y,r[i].b);
	/*	LL Max=0;
		for(map<int,LL>::iterator it=m.begin();it->x<r[i].b&&it!=m.end();it++)
		Max=max(Max,it->y); */
		it--;
		dp[i]=it->y+r[i].h;
		m[r[i].a]=max(m[r[i].a],dp[i]); 
		LL Max=m[r[i].a];
		it=m.find(r[i].a);
		it++;
		for(;it!=m.end();){
			if(it->y<=Max){
				int aa=it->x;
				it++;
				m.erase(aa);
			}
			else{
				break;
			}
		}
		ans=max(ans,dp[i]);
	}
	printf("%I64d\n",ans);
}