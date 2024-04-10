#include <bits/stdc++.h>

using namespace std;

int a[500005];
long long S[500005];

int main(){
	int n;
	scanf("%d", &n);
	S[0]=0;
	for(int i=0; i < n; ++i){
		scanf("%d", a+i);
		S[i+1]=S[i]+a[i];
	}
	int num=0;
	long long ans=0;
	for(int i=1; i < n; ++i){
		if(3*S[i]==S[n]*2){
			ans += num;
		}
		if(3*S[i] == S[n])
			++num;
	}
	printf("%I64d\n", ans);
}