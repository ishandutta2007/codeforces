#include<cstdio>
#include<vector>
using namespace std;
typedef long long ll;
typedef long double ldb;
typedef unsigned int uint;
const int MAXA = 1e6 + 5;

inline void chk_max(int &a,int b){ if(a<b) a=b;}

vector<int> pos[MAXA];

int main(void)
{
	int n;
	scanf("%d",&n);
	int maxa=0;
	for(int i=1; i<=n; ++i)
	{
		int a;
		scanf("%d",&a);
		pos[a].push_back(i);
		chk_max(maxa,a);
	}
	
	ldb ans=0;
	for(int i=1; i<=maxa; ++i)
	{
		pos[i].push_back(n+1);
		
		ll cnt=0;
		for(uint j=0; j<pos[i].size()-1; ++j)
			cnt += (ll)pos[i][j]*(pos[i][j+1]-pos[i][j])*2 - 1;
		ans += (ldb)cnt / ((ll)n*n);
	}
	printf("%.15lf",(double)ans);
	return 0;
}