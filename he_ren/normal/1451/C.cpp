#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e6 + 5;

char s[MAXN], t[MAXN];

void solve(void)
{
	int n,d;
	scanf("%d%d%s%s",&n,&d,s+1,t+1);
	
	static int freq[30];
	memset(freq,0,sizeof(freq));
	
	for(int i=1; i<=n; ++i) ++freq[s[i] - 'a'];
	for(int i=1; i<=n; ++i) --freq[t[i] - 'a'];
	
	for(int i=0; i<26; ++i)
	{
		if(freq[i] < 0 || freq[i] % d){ printf("No\n"); return;}
		if(i == 25 && freq[i]){ printf("No\n"); return;}
		freq[i+1] += freq[i];
	}
	printf("Yes\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}