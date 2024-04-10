#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef pair<int,int>pi;
typedef vector<int>vi;
typedef long long ll;
const int maxn=1e5+20;
const int M=998244353;
int _,n,a[maxn],sum[maxn],k;
int main(){
	scanf("%d",&_);
	while (_--){
		scanf("%d%d",&n,&k);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		for (int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
		if (sum[n]==k){puts("NO");continue;}
		for (int i=1;i<n;i++) if (sum[i]==k){swap(a[i],a[i+1]);}
		puts("YES");
		for (int i=1;i<=n;i++) printf("%d ",a[i]);puts("");
	}
	return 0;
}