//CF301
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
int main(){
	int n;
	scanf("%d",&n);
	vector<int>num;
	vector<int>abss;
	for(int i=0;i<2*n-1;i++)
	{
		int e;
		scanf("%d",&e);
		num.pb(e);
		abss.pb(abs(e));
	}
	sort(num.begin(),num.end());
	sort(abss.begin(),abss.end());
	int minus=0;
	for(int i=0;i<num.size();i++)
	{
		if(num[i]<0)
		{
			minus++;
		}
	}
	int ret=0;
	if(minus%2==1 && n%2==0)
	{
		ret=-1*abss[0];
		for(int i=1;i<abss.size();i++)
		{
			ret+=abss[i];
		}
	}
	else{
		ret=0;
		for(int i=0;i<abss.size();i++)
		{
			ret+=abss[i];
		}
	}
	printf("%d\n",ret);
}