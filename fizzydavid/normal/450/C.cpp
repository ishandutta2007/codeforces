#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<set>
#include<utility>
#include<vector>
using namespace std;
#define ff first
#define ss second
#define pb push_back 
#define mp make_pair
const int INF=1<<28;
long long n,m,k;
int main()
{
	cin>>n>>m>>k;
	k++;
	if(k>n+m-1)puts("-1");
	else if(k<=n&&k<=m)cout<<max(n/k*m,m/k*n);
	else if(k<=n)cout<<n/k*m;
	else if(k<=m)cout<<m/k*n;
	else if(k>n&&k>m)cout<<max(m/(k-n+1),n/(k-m+1));
	else if(k>n)cout<<m/(k-n+1);
	else cout<<n/(k-m+1);
// 	system("pause");
	return 0;
}