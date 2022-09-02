#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
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
typedef long long ll;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
int main()
{
	int n; cin >> n;
	string s; cin >> s;
	for(int i=0;i<s.size();i++)
	{
		for(int j=i+1;j<s.size();j++)
		{
			if(s[i] == '.' || s[j] == '.') continue;
			int ad = j-i;
			int cur = j;
			for(int k=0;k<3;k++)
			{
				cur += ad;
				if(cur >= n) goto FAIL;
				if(s[cur] == '.') goto FAIL;
			}
			cout << "yes" << endl; return 0;
			FAIL:;
		}
	}cout << "no" << endl;
}