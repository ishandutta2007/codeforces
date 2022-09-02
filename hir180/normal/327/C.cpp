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
long long bin[200005];
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
	string str;
	cin >> str;
	int k;
	cin >> k;
	bin[0]=1;
	for(int i=1;i<=200000;i++)
	{
		bin[i]=bin[i-1]*2LL%mod;
	}
	long long ans=0;
	for(int i=0;i<str.size();i++)
	{
		if(str[i]=='0' || str[i]=='5') ans+=bin[i];
		ans%=mod;
	}
	long long ans1=1,ans2=1;
	long long pow1=1LL*str.size()*k;
	long long pow2=1LL*str.size();
	long long b[55];
	ans1=modpow(2,pow1);
	ans1=(ans1+mod-1)%mod;
	ans2=modpow(2,pow2);
	ans2=(ans2+mod-1)%mod;
	long long c[55],ans3=1;
	ans3=modpow(ans2,mod-2);
	cout << (ans1*ans3%mod)*ans%mod << endl;
}