//Bokan ga bokka--nn!!
//Daily Lunch Special Tanoshii !!
//HIR180
//IOI2014N
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
	int t; cin >> t;
	while(t--)
	{
		string str; cin >> str;
		vector<int>vec;
		for(int i=12;i>=1;i--)
		{
			if(12%i!=0) continue;
			for(int j=0;j<i;j++)
			{
				for(int k=j;k<12;k+=i)
				{
					if(str[k]=='O') goto out;
				}
				vec.pb(12/i);
				goto over;
				out:;
			}
			over:;
		}
		cout << vec.size();
		for(int i=0;i<vec.size();i++) cout << " " << vec[i] << "x" << 12/vec[i];
		cout << endl;
	}
}