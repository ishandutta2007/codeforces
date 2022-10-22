#include <bits/stdc++.h>

using namespace std;

long long Max, Maxn, Min, Minn;

int main(){
	int n;
	scanf("%d", &n);
	Max=0, Min=1000000005;
	for(int i=0; i < n; ++i){
		int b;
		scanf("%d", &b);
		if(b < Min){
			Min=b;
			Minn=0;
		}
		if(b > Max){
			Max=b;
			Maxn=0;
		}
		if(b == Min)
			++Minn;
		if(b == Max)
			++Maxn;
	}
	if(Min == Max)
		printf("0 %I64d\n", (Minn*(Minn-1))/2);
	else
		printf("%I64d %I64d\n", Max-Min, Maxn*Minn);
}