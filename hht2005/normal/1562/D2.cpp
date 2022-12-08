#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10;
char s[N];
int sum[N];
vector<int>pos[N*2];
void print(int l,int r) {
	int L=sum[r]-sum[l-1],S=sum[l-1]+N;
	if(L>0)S+=L/2+1;
	else S-=-L/2+1;
	printf("%d\n",*lower_bound(pos[S].begin(),pos[S].end(),l));
}
int main() {
	int T,n,q,l,r;
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d",&n,&q);
		scanf("%s",s+1);
		for(int i=-n;i<=n;i++)pos[i+N].clear();
		for(int i=1;i<=n;i++) {
			sum[i]=sum[i-1]+(i%2?1:-1)*(s[i]=='-'?-1:1);
			pos[sum[i]+N].push_back(i);
		}
		while(q--) {
			scanf("%d%d",&l,&r);
			if(sum[l-1]==sum[r])puts("0");
			else if((sum[r]-sum[l-1])%2) {
				puts("1");
				print(l,r);
			} else {
				puts("2");
				printf("%d ",l);
				print(l+1,r);
			}
		}
	}
	return 0;
}