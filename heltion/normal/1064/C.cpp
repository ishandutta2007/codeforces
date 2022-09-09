#include<bits/stdc++.h>
#define maxn 120000
using namespace std;
char s[maxn];
int main(){
	int n;
	scanf("%d %s", &n, s);
	sort(s, s + n);
	printf("%s", s);
}