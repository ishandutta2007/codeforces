#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define x first
#define y second
#define N 131072
#define pi acos(-1)
typedef complex<double> C;
int main()
{
	int n;
	scanf("%d",&n);
	char c[55];
	scanf("%s",c);
	int ans=1e9;
	for(int i = 0;i<=n-4;i++){
		int tot=0;
		tot+=min(abs(c[i]-'A'),26-abs(c[i]-'A'));
		tot+=min(abs(c[i+1]-'C'),26-abs(c[i+1]-'C'));
		tot+=min(abs(c[i+2]-'T'),26-abs(c[i+2]-'T'));
		tot+=min(abs(c[i+3]-'G'),26-abs(c[i+3]-'G'));
		ans=min(ans,tot);
	}
	printf("%d\n",ans);
}