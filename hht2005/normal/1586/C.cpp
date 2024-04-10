#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
char s[N];
int sum[N];
#define bh(i,j) ((i)*(m)+j)
int main() {
	int n,m,q,l,r;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n*m;i++) {
		char ch=getchar();
		while(ch!='.'&&ch!='X')ch=getchar();
		s[i]=ch;
	}
	for(int i=1;i<n;i++) {
		for(int j=1;j<m;j++) {
			// if(s[bh(i,j)]!='.')continue;
			if(s[bh(i-1,j)]!='.'&&s[bh(i,j-1)]!='.')
				sum[j]=1;
		}
	}
	for(int i=1;i<m;i++)sum[i]+=sum[i-1];
	scanf("%d",&q);
	while(q--) {
		scanf("%d%d",&l,&r);
		l--,r--;
		if(sum[l]==sum[r])puts("YES");
		else puts("NO");
	}
	return 0;
}