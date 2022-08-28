#include<bits/stdc++.h>
using namespace std;
char s[100010];
int n;
int main(){
	scanf("%d%s",&n,s);
	sort(s,s+n);
	puts(s);
	return 0;
}