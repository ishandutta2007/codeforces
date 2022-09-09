#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

inline int get_l(ll x)
{
	int res = 0;
	while(x) ++res, x/=10;
	return res;
}

int pw2[15], pw3[15], pw10[15];

void solve(void)
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	printf("%d %d\n",pw2[a-c+1] * pw10[c], pw3[b-c+1] * pw10[c]);
}

int main(void)
{
	for(ll cur=1; get_l(cur) <= 9; cur *= 2) pw2[get_l(cur)] = cur;
	for(ll cur=1; get_l(cur) <= 9; cur *= 3) pw3[get_l(cur)] = cur;
	for(ll cur=1; get_l(cur) <= 9; cur *= 10) pw10[get_l(cur)] = cur;
	
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}