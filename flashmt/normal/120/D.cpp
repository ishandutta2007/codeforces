#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int a[55][55];

int main()
{
	freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
	int n,m,x,re=0,A,B,C;
	cin >> m >> n;
	for (int i=1;i<=m;i++) for (int j=1;j<=n;j++) cin >> x, a[i][j]=a[i][j-1]+a[i-1][j]-a[i-1][j-1]+x;
	cin >> A >> B >> C;
	vector <int> s;
	s.push_back(A); 
	s.push_back(B); 
	s.push_back(C);
	sort(s.begin(),s.end());
	for (int i=1;i<n;i++)
		for (int j=i+1;j<n;j++)
		{
			vector <int> ss;
			ss.push_back(a[m][i]);
			ss.push_back(a[m][j]-a[m][i]);
			ss.push_back(a[m][n]-a[m][j]);
			sort(ss.begin(),ss.end());
			re+=ss==s;
		}
	for (int i=1;i<m;i++)
		for (int j=i+1;j<m;j++)
		{
			vector <int> ss;
			ss.push_back(a[i][n]); 
			ss.push_back(a[j][n]-a[i][n]); 
			ss.push_back(a[m][n]-a[j][n]);
			sort(ss.begin(),ss.end());
			re+=ss==s;
		}
	cout << re << endl;
}