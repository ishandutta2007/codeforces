#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
char s[N];
int t[3];
int main() {
	t[2]=t[1]=-1e9;
	scanf("%s",s+1);
	int n=strlen(s+1),sum=0,ans=0;//ljhgjkd
	for(int i=1;i<=n;i++) {
		if(s[i]=='0') {
			ans+=max(max(t[0],t[1]),t[2])+1;
			t[2]=t[1]=-1e9;
			sum=t[0]=0;
			continue;
		}
		sum=(sum+s[i]-'0')%3;
		t[sum]++;
		int Max=max(max(t[0],t[1]),t[2]);
		t[sum]=max(t[sum],Max);
	}
	printf("%d\n",ans+max(max(t[0],t[1]),t[2]));
	return 0;
}