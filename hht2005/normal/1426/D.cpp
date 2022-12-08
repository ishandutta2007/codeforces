#include<bits/stdc++.h>
using namespace std;
const int maxn=200010;
int a[maxn];
map<long long,int>s;
int main() {
	int n,cnt=0,las=1;
	long long sum=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	s[0]=1;
	for(int i=1;i<=n;i++) {
		sum+=a[i];
		if(s[sum]>=las)cnt++,las=i;
		s[sum]=i+1;
	}
	printf("%d\n",cnt);
	return 0;
}