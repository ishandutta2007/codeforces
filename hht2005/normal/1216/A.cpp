#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
char s[maxn];
int main() {
	int n,a=0,b=0,cnt=0;
	scanf("%d%s",&n,s+1);
	for(int i=1;i<=n;i++) {
		if(s[i]=='a')a++;
		else b++;
		if(i%2==0&&a!=b) {
			if(a<b)a++,b--,s[i]='a';
			else a--,b++,s[i]='b';
			cnt++;
		}
	}
	printf("%d\n%s\n",cnt,s+1);
	return 0;
}