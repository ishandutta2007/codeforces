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
long long rui[200005]={};
vector<int>num;
int main(){
	int n,k;
	cin >> n >> k;
	num.pb(-1);
	for(int i=1;i<=n;i++)
	{
		int s;
		cin >> s;
		num.pb(s);

	}

	for(int i=1;i<=n;i++) rui[i]=rui[i-1]+num[i];

	long long ans=0;
	long long curmax=0;
	int curmaxidx,nowidx,sideidx;

	for(int i=k+1;i<=n-k+1;i++)
	{
		long long prev=curmax;
		curmax=max(curmax,rui[i-1]-rui[i-k-1]);
		if(curmax==rui[i-1]-rui[i-k-1] && curmax>prev && curmax+rui[i+k-1]-rui[i-1]>ans ) sideidx=curmaxidx=i-k;
        else if(curmax==rui[i-1]-rui[i-k-1] && curmax>prev) sideidx=i-k;
		prev=ans;
		ans=max(ans,curmax+rui[i+k-1]-rui[i-1]);
		if(ans==curmax+rui[i+k-1]-rui[i-1] && ans>prev) { nowidx=i; curmaxidx=sideidx;}
	}

	cout << curmaxidx << " " << nowidx << endl;
}