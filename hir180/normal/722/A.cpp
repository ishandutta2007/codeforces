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
#include <cassert>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
#define mod 924844033
int n; string s;
int main()
{
	cin >> n >> s;
	if(n == 12){
		int val = 10*(s[0]-'0')+(s[1]-'0');
		if(1<=val&&val<=12){}
		else{
			if(s[1] == '0') s[0] = '1';
			else s[0] = '0';
		}
	}
	else{
		int val = 10*(s[0]-'0')+(s[1]-'0');
		if(0<=val&&val<=23){}
		else{
			s[0] = '0';
		}
	}
	int val = 10*(s[3]-'0')+(s[4]-'0');
	if(0<=val&&val<=59){}
	else{
		s[3] = '0';
	}
	cout << s << endl;
}