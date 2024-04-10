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
bool outx[1005]={};
bool outy[1005]={};
int n,m;
int x[100005],y[100005];
int main(){
	cin >> n >> m;
	for(int i=0;i<m;i++)
	{
		cin >> x[i] >> y[i];
		outx[x[i]]=true;
		outy[y[i]]=true;
	}
	int val=0;
	for(int i=2;i<n;i++)
	{
		if(!outx[i]) val++;
	}
	for(int i=2;i<n;i++)
	{
		if(!outy[i]) val++;
	}
	if(n%2==1){ if(!outx[(n+1)/2] && !outy[(n+1)/2]) val--;}
	cout << val << endl;
}