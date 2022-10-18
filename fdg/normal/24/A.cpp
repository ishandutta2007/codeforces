#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

/*#ifndef ONLINE_JUDGE
int AA=(int)freopen("input.txt","r",stdin);
int BB=(int)freopen("output.txt","w",stdout);
#endif*/

#define ll long long

using namespace std;

int main()
{
	int n,a,b,c,ans=1000000000,D[102][102]={0};
	cin >> n;
	for(int i=0;i<n;i++)
	{
		cin >> a >> b >> c;
		D[a][b]=c;
	}
	vector <int> start(1,1);
	for(int i=2;i<=n;i++)
	{
		int cur=start[i-2],last=-1;
		if (i>2) last=start[i-3];
		for(int i=1;i<=n;i++)
			if ((D[cur][i]!=0||D[i][cur]!=0)&&i!=last)
			{
				start.push_back(i);
				break;
			}
	}
//	for(int i=0;i<start.size();i++)
//		cout << start[i] << endl;
	int cur1=0,cur2=0;
	if (D[start[n-1]][start[0]]==0) cur1+=D[start[0]][start[n-1]];
	else cur2+=D[start[n-1]][start[0]];
	for(int i=0;i<start.size()-1;i++)
		if (D[start[i]][start[i+1]]==0) cur1+=D[start[i+1]][start[i]];
		else cur2+=D[start[i]][start[i+1]];
	cout << min(cur1,cur2) << endl;
	return 0;
}