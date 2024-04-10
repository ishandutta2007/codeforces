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
int n;
string str;
int main()
{
	cin >> n;
	cin >> str;
	int ans=0;
	for(int i=n;i<str.size();i+=n)
	{
		if(str[i-1]==str[i-2] && str[i-2]==str[i-3])
		{
			ans++;
		}
	}
	cout << ans << endl;
}