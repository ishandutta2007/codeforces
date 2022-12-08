#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
int k[maxn];
int main() {
	int n,a,b,K,h;
	scanf("%d%d%d%d",&n,&a,&b,&K);
	for(int i=1;i<=n;i++) {
		scanf("%d",&h);
		k[i]=h%(a+b);
		if(!k[i])k[i]+=a+b;
		k[i]=(k[i]-1)/a;
	}
	sort(k+1,k+n+1);
	int T=k[1],cnt=0;
	while(T<=K&&cnt<n) {
		cnt++;
		T+=k[cnt+1];
	}
	printf("%d\n",cnt);
	return 0;
}