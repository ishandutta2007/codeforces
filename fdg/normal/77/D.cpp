#include <cstdio>
#include <map>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

#define ll long long

using namespace std;

char D[1005][1005]={0};
int ver[]={0,1,4,6,8,10,12},
	hor[]={0,1,5,7,8,10,13};
int F[255][255]={0};

char figure[14][10]={".........",
"....O....",
".........",
".........",
"..O...O..",
"O.......O",
"..O.O.O..",
"O...O...O",
"O.O...O.O",
".........",
"O.O.O.O.O",
".........",
"O.OO.OO.O",
"OOO...OOO"};

bool isVer(int v)
{
	for(int t=0;t<7;t++)
		if (ver[t]==v) return true;
	return false;
}

bool isHor(int v)
{
	for(int t=0;t<7;t++)
		if (hor[t]==v) return true;
	return false;
}

int verify(int x,int y)
{
	for(int t=0;t<14;t++)
	{
		bool ok=true;
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++)
				if (figure[t][i*3+j]!=D[x+i][y+j]) ok=false;
		if (ok) return t;
	}
	return -1;
}

ll mod=1000000007;

ll dp_c[255]={0},dp2[255]={0};

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<4*n+1;i++)
		cin >> D[i];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			F[i][j]=verify(4*i+1,4*j+1);
//			cout << F[i][j] << "	";
		}
//		cout << endl;
	}
	for(int i=0;i<m;i++)
	{
		if (n%2==1) dp_c[i]=0;
		else
		{
			bool norm=true;
			for(int j=0;j<n;j++)
			{
				bool finded=false;
				for(int t=0;t<7;t++)
					if (ver[t]==F[j][i]) finded=true;
				if (!finded)
				{
					norm=false;
					break;
				}
			}
			if (norm) dp_c[i]=1;
			else dp_c[i]=0;
		}
	}
	for(int j=0;j<m-1;j++)
	{
		int tmp[255]={0};
		tmp[0]=1;
		for(int i=1;i<=n;i++)
		{
			tmp[i]=0;
			if (i>1)
			{
				if (isVer(F[i-2][j])&&isVer(F[i-1][j])&&isVer(F[i-2][j+1])&&isVer(F[i-1][j+1])) tmp[i]=(tmp[i]+tmp[i-2])%mod;
			}
			if (isHor(F[i-1][j])&&isHor(F[i-1][j+1])) tmp[i]=(tmp[i]+tmp[i-1])%mod;
		}
		dp2[j]=tmp[n];
	}
	ll ans[255]={0};
	ans[0]=dp_c[0];
	for(int j=1;j<m;j++)
	{
		ans[j]=(ans[j-1]*dp_c[j])%mod;
		ans[j]=(ans[j]+(j-2>=0 ? ans[j-2] : 1)*(dp2[j-1]-(dp_c[j]&&dp_c[j-1] ? 1 : 0)))%mod;
	}
	cout << ans[m-1] << endl;
	return 0;
}