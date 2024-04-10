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
int n,m;
int main(){
	string str;
	cin >> str;
	long long ans=0LL;
	for(int i=0;i<str.size();i++)
	{
		if(str[i]=='1')
		{
			long long ret=1LL;
			int x=i;
			int y=str.size()-i-1;
			while(x--)
			{
				ret*=2LL;
				ret%=mod;
			}
			while(y--)
			{
				ret*=4LL;
				ret%=mod;
			}
			ans+=ret;
			ans%=mod;
		}
	}
	cout << ans << endl;
}