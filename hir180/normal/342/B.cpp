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
int main(){
	int n,m,s,f;
	cin >> n >> m >> s >> f;
	map<int,P>ma;
	for(int i=0;i<m;i++)
	{
		int a,b,c;
		cin >> a >> b >> c;
		ma[a]=mp(b,c);
	}
	string ret="";
	for(int i=1;;i++)
	{
		if(ma[i].first && ma[i].second)
		{
			if(s<f && min(ma[i].second,s+1)-max(s,ma[i].first)<0)
			{
				s++;
				ret.pb('R');
			}
			else if(s>f && min(ma[i].second,s)-max(s-1,ma[i].first)<0) 
			{
				s--;
				ret.pb('L');
			}
			else
			{
				ret.pb('X');
			}
		}
		else
		{
			if(s<f)
			{
				s++;
				ret.pb('R');
			}
			else
			{
				s--;
				ret.pb('L');
			}
		}
		if(s==f)
		{
			cout << ret << endl;
			//cin >> ret;
			return 0;
		}
	}
}