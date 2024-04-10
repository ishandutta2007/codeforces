#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int p[maxn],c[maxn],n;
char s[maxn];
vector<int>t[26];
void add(int x) {
	for(int i=x;i<=n;i+=i&-i)c[i]++;
}
int qry(int x) {
	int sum=0;
	for(int i=x;i;i-=i&-i)sum+=c[i];
	return sum;
}
int main() {
	long long ans=0;
	scanf("%d%s",&n,s+1);
	for(int i=1;i<=n;i++)
		t[s[i]-'a'].push_back(i);
	for(int i=1;i<=n;i++) {
		p[n-i+1]=*t[s[i]-'a'].rbegin();
		t[s[i]-'a'].pop_back();
		ans+=qry(p[n-i+1]);
		add(p[n-i+1]);
	}
	printf("%lld\n",ans);
	return 0;
}