#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e6 + 5;
const int LB = 20 + 5;

int lb[MAXN];

char s[MAXN];
int len[MAXN], nxt[MAXN];

int st[MAXN][LB];
void st_init(int a[],int n)
{
	for(int i=1; i<=n; ++i) st[i][0] = a[i];
	for(int k=1; k<=lb[n]; ++k)
		for(int i=1; i+(1<<k)-1<=n; ++i)
			st[i][k] = max(st[i][k-1], st[i+(1<<(k-1))][k-1]);
}
inline int query_max(int l,int r){ int k=lb[r-l+1]; return max(st[l][k], st[r-(1<<k)+1][k]);}

inline bool check(int l,int r,int d)
{
	return query_max(l+d-1,r) >= d;
}

int main(void)
{
	lb[1] = 0;
	for(int i=2; i<MAXN; ++i) lb[i] = lb[i>>1] + 1;
	
	int n;
	scanf("%d%s",&n,s+1);
	
	for(int i=1,j=1; i<=n; i=j)
	{
		while(j<=n && (s[i]!='0') == (s[j]!='0')) ++j;
		for(int k=i; k<j; ++k)
			len[k] = max(len[k], k-i+1),
			nxt[k] = max(nxt[k], j);
	}
	for(int i=1,j=1; i<=n; i=j)
	{
		while(j<=n && (s[i]!='1') == (s[j]!='1')) ++j;
		for(int k=i; k<j; ++k)
			len[k] = max(len[k], k-i+1),
			nxt[k] = max(nxt[k], j);
	}
	
	st_init(len,n);
	
	printf("%d ",n);
	for(int k=2; k<=n; ++k)
	{
		int res = 0;
		
		int now = 1;
		while(now+k-1 <= n)
		{
			if(nxt[now] - now >= k)
			{
				res += (nxt[now] - now) / k;
				now = nxt[now] - (nxt[now] - now) % k;
				continue;
			}
			
			if(!check(now,n, k)) break;
			
			int l=k, r=n-now+1;
			while(l<r)
			{
				int mid = (l+r)>>1;
				if(check(now,now+mid-1, k)) r = mid;
				else l = mid+1;
			}
			
			++res;
			now += l;
		}
		printf("%d ",res);
	}
	return 0;
}