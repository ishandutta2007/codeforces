#include<bits/stdc++.h>
#define maxn 120
using namespace std;
char s[maxn];
int main(){
	int n, tot = 0;
	scanf("%d %s", &n, s);
	for(int i = 0; i < n; i += 1) tot += s[i] -= '0';
	for(int sum = 0; sum <= tot; sum += 1){
		int ps = 0, time = 0;
		for(int i = 0; i < n; i += 1){
			ps += s[i];
			if(ps > sum) break;
			if(ps == sum) ps -= sum, time += 1;
		}
		if(ps == 0 && sum * time == tot && time > 1){
			printf("YES");
			return 0;
		}
	}
	printf("NO");
}