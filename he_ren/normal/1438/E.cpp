#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;
const int lb = 30;
const int LB = lb + 5;

inline int mx_dig(int x)
{
	for(int i=0;; ++i)
		if((x>>i) == 1) return i;
}

int n;
int a[MAXN];

ll sum[MAXN];
inline bool check_ok(int l,int r)
{
	return l+1 <= r-1 && (a[l] ^ a[r]) == sum[r-1] - sum[l];
}

int lpos[LB][3];
void push_back(int k,int pos)
{
	lpos[k][0] = lpos[k][1];
	lpos[k][1] = pos;
}

ll get_ans(bool larg)
{
	for(int i=1; i<=n; ++i)
		sum[i] = sum[i-1] + a[i];
	
	int res = 0;
	
	memset(lpos,0,sizeof(lpos));
	for(int i=1; i<=n; ++i)
	{
		int dig = mx_dig(a[i]);
		push_back(dig, i);
		
		for(int j=dig+larg; j<=lb; ++j)
			for(int k=0; k<=1; ++k)
				if(lpos[j][k] && check_ok(lpos[j][k], i))
					++res;
	}
	
	return res;
}

int main(void)
{
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	ll ans = get_ans(1);
	reverse(a+1,a+n+1);
	ans += get_ans(0);
	
	printf("%lld",ans);
	return 0;
}