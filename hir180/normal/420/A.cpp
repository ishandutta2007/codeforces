//IOI2014
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
	srand((unsigned int)time(NULL));
	map<char,char>ma;
	ma['A']='A';
	ma['H']='H';
	ma['I']='I';
	ma['M']='M';
	ma['O']='O';
	ma['T']='T';
	ma['U']='U';
	ma['V']='V';
	ma['W']='W';
	ma['X']='X';
	ma['Y']='Y';
	string s; cin >> s;
	string t="";
	for(int i=s.size()-1;i>=0;i--)
	{
		if(ma.find(s[i]) == ma.end()) t.pb('.');
		else t.pb(ma[s[i]]);
	}
	puts(s==t?"YES":"NO");
}