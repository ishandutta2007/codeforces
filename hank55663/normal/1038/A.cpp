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
#define index Index
using namespace std;
typedef long long LL;
int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	int cnt[26];
	char c[100005];
	scanf("%s",c);
	for(int i=0;c[i]!=0;i++){
		cnt[c[i]-'A']++;
	}
	int ans=1e9;
	for(int i=0;i<k;i++)
		ans=min(ans,cnt[i]);
	printf("%d\n",ans*k);
	return 0;
}