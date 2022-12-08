#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
char s[maxn];
int t[maxn],top;
int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		int n,sum,cnt=1;
		top=sum=0;
		scanf("%d%s",&n,s+1);
		for(int i=2;i<=n;i++) {
			if(s[i]!=s[i-1])t[++top]=cnt,cnt=0;
			cnt++;
		}
		t[++top]=cnt;
		for(int i=1,j=1;i<=top;i++) {
			while(t[j]==1&&j<=top)j++;
			if(j<=top)t[j]--;
			else i++;
			j=max(j,i+1);
			sum++;
		}
		printf("%d\n",sum);
	}
	return 0;
}