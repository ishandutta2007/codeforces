#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<ll,int> pli;
typedef pair<int,ll> pil;
#define mp make_pair
#define fir first
#define sec second
const int MAXN = 1.5e5 + 5;

int a[MAXN];
priority_queue<pli,vector<pli>,greater<pli> > q;

pil ans[MAXN];
int cnt=0;

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
		scanf("%d",&a[i]), q.push(mp(a[i],i));
	
	while(!q.empty())
	{
		pli u=q.top(); q.pop();
		if(q.empty() || q.top().fir != u.fir)
		{
			ans[++cnt] = mp(u.sec, u.fir);
			continue;
		}
		
		pli v=q.top(); q.pop();
		q.push(mp(u.fir+v.fir, v.sec));
	}
	
	sort(ans+1,ans+cnt+1);
	printf("%d\n",cnt);
	for(int i=1; i<=cnt; ++i) cout<<ans[i].sec<<' ';
	return 0;
}