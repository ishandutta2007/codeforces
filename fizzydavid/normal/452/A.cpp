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
typedef long long ll;
const int INF=1<<28;
const long long LINF=1ll<<61;
string s[8]={"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};
string s2;
int n;
int main()
{
	cin>>n>>s2;
	for(int i=0;i<8;i++)
	{
		if(n==s[i].size())
		{
			bool ok=1;
			for(int j=0;j<n;j++)
			{
				if(s2[j]!=s[i][j]&&s2[j]!='.')
				{
					ok=0;
					break;
				}
			}
			if(ok==1)
			{
				cout<<s[i];
//				system("pause");
				return 0;
			}
		}
	}
// 	system("pause");
	return 0;
}