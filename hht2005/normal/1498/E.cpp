#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int p[maxn],v[maxn],t[maxn];
signed main() {
	int n,A=0,B=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d",v+i);
		p[v[i]]++;
	}
	for(int i=1;i<=n;i++)p[i]+=p[i-1];
	for(int i=1;i<=n;i++)t[i]=p[v[i]]--;
	for(int i=1;i<=n;i++)p[t[i]]=i;
	int sum=0,las=0;
	for(int i=1;i<=n;i++) {
		sum+=v[p[i]];
		if(sum==i*(i-1)/2) {
			if(las+1<i&&v[A]-v[B]<=v[p[i]]-v[p[las+1]])A=p[i],B=p[las+1];
			las=i;
		}
	}
	printf("! %d %d\n",A,B);
	return 0;
}