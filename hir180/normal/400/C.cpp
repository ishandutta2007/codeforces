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
vector<P>cur;
void rotate90(int& tate,int& yoko,vector<P>& za,int turn)
{
	if(turn<=0) return ;
	for(int i=0;i<za.size();i++)
	{
		za[i]=mp(yoko-za[i].sc+1,za[i].fi);
	}
	swap(tate,yoko);
	rotate90(tate,yoko,za,--turn);
}
void rotate180(int& tate,int& yoko,vector<P>& za,int turn)
{
	if(turn<=0) return ;
	for(int i=0;i<za.size();i++)
	{
		za[i]=mp(za[i].fi,yoko+1-za[i].sc);
	}
	rotate180(tate,yoko,za,--turn);
}
void rotate270(int& tate,int& yoko,vector<P>& za,int turn)
{
	if(turn<=0) return ;
	for(int i=0;i<za.size();i++)
	{
		za[i]=mp(za[i].sc,tate-za[i].fi+1);
	}
	swap(tate,yoko);
	rotate270(tate,yoko,za,--turn);
}
int main()
{
	int n,m,x,y,z,p;
	cin >> n >> m >> x >> y >> z >> p;
	for(int i=0;i<p;i++)
	{
		int x,y; cin >> x >> y;
		cur.pb(mp(x,y));
	}
	x%=4;
	y%=2;
	z%=4;
	rotate270(n,m,cur,x);
	rotate180(n,m,cur,y);
	rotate90(n,m,cur,z);
	for(int i=0;i<p;i++) cout << cur[i].fi << " " << cur[i].sc << endl;
}