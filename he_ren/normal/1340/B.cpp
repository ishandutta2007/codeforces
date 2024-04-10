#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define Mp make_pair
const int MAXN = 2e3 + 5;
const int MAXD = 2e3 + 5;

const char num[11][8] = {
"1110111",
"0010010",
"1011101",
"1011011",
"0111010",
"1101011",
"1101111",
"1010010",
"1111111",
"1111011"};

vector<pii> a[MAXN];
char s[10];

bool can[MAXN][MAXD];

int main(void)
{
	int n,d;
	scanf("%d%d",&n,&d);
	for(int i=1; i<=n; ++i)
	{
		scanf("%s",s);
		for(int j=0; j<=9; ++j)
		{
			bool flag=1;
			int need=0;
			for(int k=0; k<7; ++k)
			{
				if(s[k]==num[j][k]) continue;
				if(s[k]=='1'){ flag=0; break;}
				++need;
			}
			if(flag) a[i].push_back(Mp(j,need));
		}
	}
	
	can[n+1][0]=1;
	for(int i=n; i>=1; --i)
		for(int j=0; j<=d; ++j)
		{
			for(int k=0; k<(int)a[i].size(); ++k)
				if(j >= a[i][k].second && can[i+1][j - a[i][k].second])
				{
					can[i][j] = 1;
					break;
				}
		}
	
	if(!can[1][d])
	{
		printf("-1");
		return 0;
	}
	
	int rem = d;
	for(int i=1; i<=n; ++i)
	{
		for(int k=(int)a[i].size()-1; k>=0; --k)
			if(rem >= a[i][k].second && can[i+1][ rem - a[i][k].second ])
			{
				printf("%d", a[i][k].first);
				rem -= a[i][k].second;
				break;
			}
	}
	return 0;
}