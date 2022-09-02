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
	int n;
	cin >> n;
	int ope=0;
	while(n)
	{
		int root[10];
		int m=n,cur=0;
		int maxi=0;
		while(m)
		{
			root[cur++]=m%10;
			maxi=max(maxi,m%10);
			m/=10;
		}
		n-=maxi;
		ope++;
	}
	cout << ope << endl;
}