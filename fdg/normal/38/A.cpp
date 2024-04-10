#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define double long double

const double Pi=3.1415926535897932384626;

int main()
{
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	int n,d[102]={0},a,b,ans=0;
	cin >> n;
	for(int i=0;i<n-1;i++)
		cin >> d[i];
	cin >> a >> b;
	for(int i=a-1;i<b-1;i++)
		ans+=d[i];
	cout << ans << endl;
	return 0;
}