#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;

int n;
char str[MAXN];

int main(){
	scanf("%d",&n);
	scanf("%s",str+1);
	sort(str+1,str+n+1);
	puts(str+1);
}