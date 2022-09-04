#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
using namespace std;
typedef long long LL;
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	int ans[2005];
	MEM(ans);
	char c[2005][2005];
	for(int i=0;i<n;i++){
		scanf("%s",c[i]);
		for(int j=0;c[i][j]!=0;j++)
		if(c[i][j]=='1')
		ans[j]++;
	}
	int ok=0;
	for(int i=0;i<n;i++){
		int ook=1;
		for(int j=0;j<m;j++){
			if(c[i][j]=='1'&&ans[j]==1)
			ook=0;
		}
		if(ook)
		ok=1;
	}
	if(ok)
	printf("YES\n");
	else
	printf("NO\n");
}