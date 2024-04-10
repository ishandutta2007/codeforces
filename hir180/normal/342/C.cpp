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
	int r,h;
	cin >> r >> h;
	int f=h/r;
	int val=(f+1)*r;
	val-=h;
	if(1.0*val<=1.0*r/2.0*(2.0-sqrt(3.0)))
	{
		cout << 2*f+3 << endl;
	}
	else if(2*val<=r)
	{
		cout << 2*f+2 << endl;
	}
	else
	{
		cout << 2*f+1 << endl;
	}
}