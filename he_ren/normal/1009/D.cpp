#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
using namespace std;
typedef pair<int,int> pii;
#define fir first
#define sec second
#define Mp make_pair
typedef unsigned int uint;

inline void NO(void){ printf("Impossible"); exit(0);}
int gcd(int a,int b){ return b? gcd(b,a%b): a;}

int n,m;
vector<pii> ans;

void gao(void)
{
	for(int i=1; i<=n; ++i)
		for(int j=i+1; j<=n; ++j)
			if(gcd(i,j)==1)
			{
				ans.push_back(Mp(i,j));
				if((int)ans.size()==m) return;
			}
	NO();
}

int main(void)
{
	scanf("%d%d",&n,&m);
	if(m<n-1) NO();
	
	gao();
	printf("Possible\n");
	for(uint i=0; i<ans.size(); ++i)
		printf("%d %d\n",ans[i].fir,ans[i].sec);
	return 0;
}