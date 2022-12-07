#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
using namespace std;
int n,m;
int main()
{
	cin>>n>>m;
	if(n%2==0 || m%2==0)
		cout<<n*m/2<<'\n';
	else
		cout<<(n-1)*m/2+m/2<<'\n';
	return 0;
}