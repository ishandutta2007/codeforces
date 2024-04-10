#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include <functional>
#include <queue>
 
using namespace std;
#define fi first
#define sc second
#define pb push_back
#define mp make_pair
typedef pair<int,int> P;

int dp[106][61][16][16];
int v[10][4];
int w[10][4];
string s; int n;
int main()
{
	cin >> n >> s;
	int a = 0,b = 0,c = 0,d = 0;
	for(int i=2;i<=9;i++)
	{
		for(int j=0;j<3;j++) v[i][j] = v[i-1][j];
		int x = i;
		while(x%2 == 0)
		{
			x/=2; v[i][0]++; w[i][0]++;
		}
		while(x%3 == 0)
		{
			x/=3; v[i][1]++; w[i][1]++;
		}
		while(x%5 == 0)
		{
			x/=5; v[i][2]++; w[i][2]++;
		}
		while(x%7 == 0)
		{
			x/=7; v[i][3]++; w[i][3]++;
		}
	}
	for(int i=0;i<s.size();i++)
	{
		int x = s[i]-'0';
		for(int j=2;j<=x;j++)
		{
			a += w[j][0];
			b += w[j][1];
			c += w[j][2];
			d += w[j][3];
		}
	}
	for(int i=2;i<=9;i++)
	{
		int x = i;
		dp[v[i][0]][v[i][1]][v[i][2]][v[i][3]] = 1;
	}
	for(int i=0;i<=a;i++)
	{
		for(int j=0;j<=b;j++)
		{
			for(int k=0;k<=c;k++)
			{
				for(int l=0;l<=d;l++)
				{
					if(dp[i][j][k][l] == 0) continue;
					for(int q=2;q<=9;q++)
					{
						if(i+v[q][0] <= a && j+v[q][1] <= b && k+v[q][2] <= c && l+v[q][3] <= d)
						{
							if(dp[i+v[q][0]][j+v[q][1]][k+v[q][2]][l+v[q][3]] < dp[i][j][k][l]+1)
							{
								dp[i+v[q][0]][j+v[q][1]][k+v[q][2]][l+v[q][3]] = dp[i][j][k][l]+1;
							}
						}
					}
				}
			}
		}
	}
	vector<int>vec;
	int x = a,y = b,z = c,w = d;
	int sz = dp[a][b][c][d];
	while(vec.size() < sz)
	{
		for(int q=9;q>=2;q--)
		{
			if(x < v[q][0] || y < v[q][1] || z < v[q][2] || w < v[q][3]) continue;
			
			if(dp[x-v[q][0]][y-v[q][1]][z-v[q][2]][w-v[q][3]]+1 ==  dp[x][y][z][w])
			{
				vec.pb(q);
				x -= v[q][0];
				y -= v[q][1];
				z -= v[q][2];
				w -= v[q][3]; break;
			}
		}
	}
	sort(vec.begin(),vec.end(),greater<int>());
	for(int i=0;i<vec.size();i++) cout << vec[i];
	cout << endl;
}