#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
char s[maxn];
int main() {
	int n;
	scanf("%d%s",&n,s+1);
	sort(s+1,s+n+1);
	printf("%s\n",s+1);
	return 0;
}