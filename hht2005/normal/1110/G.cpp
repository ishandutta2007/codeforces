#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
#define add(a,b) S[a].push_back(b),S[b].push_back(a)
int d[N];
char s[N];
vector<int>S[N];
int main() {
	int T,n,a,b;
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&n);
		for(int i=1;i<=4*n;i++) {
			S[i].clear();
			d[i]=0;
		}
		for(int i=1;i<n;i++) {
			scanf("%d%d",&a,&b);
			add(a,b);
			d[a]++,d[b]++;
		}
		scanf("%s",s+1);
		int N=n;
		for(int i=1;i<=n;i++)
			if(s[i]=='W') {
				d[i]++;
				add(i,N+1);
				d[++N]=3;
				add(N,N+1);
				add(N,N+2);
				d[++N]=1;
				d[++N]=1;
			}
		int F=0,C=0;
		for(int i=1;i<=N;i++) {
			if(d[i]>=4)F=1;
			else if(d[i]==3) {
				C++;
				int c1=0;
				for(int j:S[i])
					c1+=d[j]>1;
				if(c1>=2)F=1;
			}
		}
		if(F)puts("White");
		else if(C==2&&N%2==1)puts("White");
		else puts("Draw");
	}
	return 0;
}