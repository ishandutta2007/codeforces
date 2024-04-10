#include<bits/stdc++.h>
using namespace std;
const int maxn=3010;
map<int,map<int,int>>s;
int a[maxn];
int main() {
	int T,n;
	scanf("%d",&T);
	while(T--) {
		s.clear();
		scanf("%d",&n);
		long long ans=0;
		for(int i=1;i<=n;i++)
			scanf("%d",a+i);
		for(int i=n-1;i>=1;i--) {
			for(int j=1;j<i;j++)ans+=s[a[j]][a[i]];
			for(int j=i+1;j<=n;j++)s[a[i]][a[j]]++;
		}
		printf("%lld\n",ans);
	}
	return 0;
}