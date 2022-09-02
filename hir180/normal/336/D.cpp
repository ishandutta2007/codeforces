//E? Nanndatte?
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
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
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 2000000000
#define mod 1000000007
long long modpow(long long x,long long n)
{
	long long res=1;
	while(n>0)
	{
		if(n&1) res=res*x%mod;
		x=x*x%mod;
		n>>=1;
	}
	return res;
}


int main(){
	long long int n,m,g;
	cin >> n >> m >> g;
	if(g==n && m==1)
	{
		cout << 0 << endl;
		return 0;
	}
	if(!n && g==m && g==1) { cout << 1 << endl; return 0;}
	if(!n && g){ cout << 0 << endl; return 0;}
	if(!n && !g){ cout << 1 << endl; return 0;}
	if(!m)
	{
		if(n%2==g) cout <<0 << endl;
		else cout << 1 << endl;
		return 0;
	}

	long long fir=1LL;
	long long sec=1LL;
	for(int i=0;i<m-1;i++)
	{
		fir=(fir*(n-g+m-1-i))%mod;
	}

	for(int i=0;i<m-1;i++)
	{
		sec=(sec*(i+1))%mod;
	}
	fir=(fir*modpow(sec,mod-2LL))%mod;
	long long ret=fir;
	long long prev;
	for(int i=g+2;i<=n;i+=2)
	{
		if(i==n && m==1) break;
		prev=fir;
		prev=(prev*(n-i+2))%mod;
		prev=(prev*(n-i+1))%mod;
		long long t=((((n+m-i+1))%mod)*((n+m-i)%mod))%mod;
		prev=(prev*modpow(t,mod-2LL))%mod;
		ret+=prev;
		ret%=mod;
		fir=prev;
	}
	if(m==1 && n%2!=g) ret++;
	ret%=mod;
	cout << ret << endl;
}