#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <iostream>
using namespace std;
#define N 5050
char w[N],t[N];
int n;
bool check() {
	int i,flg=1;
	for(i=1;i<=n;i++) if(t[i]!=t[n-i+1]) return 0;
	for(i=1;i<=n;i++) if(t[i]!=w[i]) {
		flg=0; break;
	}
	if(!flg) return 1;
	else return 0;
}
int main() {
	scanf("%s",w+1); n=strlen(w+1);
	int i,flg=1,j;
	for(i=2;i<=n/2;i++) if(w[i]!=w[1]) {flg=0; break;}
	if(flg) {puts("Impossible"); return 0;}
	
	for(i=1;i<=n/2;i++) {
		int o=0;
		for(j=i+1;j<=n;j++) t[++o]=w[j];
		for(j=1;j<=i;j++) t[++o]=w[j];
		if(check()) {puts("1"); return 0;}
	}
	puts("2");
}