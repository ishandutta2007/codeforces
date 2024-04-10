#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

long long p[3000]={0}, q[3000]={0};
char s[3000];
int main(){
	scanf("%s", s);
	int n = strlen(s);
	for(int i=0;i<n;i++){
		for(int j=0;i+j<n && j<=i;j++){
			if(s[i+j] == s[i-j]){ p[i+j]++; q[i-j]++; }
			else break;
		}
		for(int j=0;i+j+1<n && j<=i;j++){
			if(s[i+j+1] == s[i-j]){ p[i+j+1]++; q[i-j]++; }
			else break;
		}
	}
	long long ans = 0;
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			ans += p[i] * q[j];
	printf("%I64d\n", ans);
	return 0;
}