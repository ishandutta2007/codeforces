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
int main()
{
	int n;
	cin>>n;
	for(int l=2;l<=10;l++)
	{
		for(int i=0;i<(1<<l);i++)
		{
			long long k=0;
			int c4=0,c7=0;
			for(int j=l-1;j>=0;j--)
			{
				if((i>>j)&1)k=k*10+7,c7++;else k=k*10+4,c4++;
			}
			if(k>=n&&c4==c7){cout<<k;return 0;}
		}
	}
}