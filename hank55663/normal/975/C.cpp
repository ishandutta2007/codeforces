#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define LL long long
#define y second
#define x first
using namespace std;
int main(){
	int n,q;
	scanf("%d %d",&n,&q);
	LL a[200005];
	a[0]=0;
	for(int i = 1;i<=n;i++){
		scanf("%lld",&a[i]);
		a[i]+=a[i-1];
	}
	a[n+1]=3e18;
	LL last=0;
	while(q--){
		LL k;
		scanf("%lld",&k);
		last+=k;
		int ans=n-(upper_bound(a,a+n+1,last)-a)+1;
		if(ans==0){
			ans=n;
			last=0;
		}
		printf("%d\n",ans);
	}
}