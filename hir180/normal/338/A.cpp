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
#define mod 1000000009
int main(){
	long long n,m,k;
	cin >> n >> m >> k;
	long long vac=n-m;
	if(vac*k>=n)
	{
		cout << m << endl;
		return 0;
	}

	long long zan=n-(vac*k);
	long long val=0;
	long long loop=zan/k;
	long long bin=1LL;
	for(int i=0;i<loop/20;i++)
	{
		bin=(bin*1048576)%mod;
	}
	bin=(bin*1LL<<(loop%20+1))%mod;
	bin=(bin-2LL+mod)%mod;
	bin=(bin*k)%mod;
	val=bin;
	val=(val+(zan%k+(vac*(k-1)))%mod)%mod;
	cout << val << endl;
}