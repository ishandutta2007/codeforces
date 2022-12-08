#include<bits/stdc++.h>
using namespace std;
int t[26];
char s[100010];
int main() {
	int n,k;
	scanf("%d%d",&n,&k);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)t[s[i]-'A']++;
	int mi=1e9;
	for(int i=0;i<k;i++)
		mi=min(mi,t[i]);
	printf("%d\n",mi*k);
	return 0;
}