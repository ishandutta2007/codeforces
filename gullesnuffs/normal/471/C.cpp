#include <bits/stdc++.h>

using namespace std;

long long n;

bool can(long long h){
	long long need=(h*(h+1)*3)/2-h;
	if(n < need)
		return 0;
	if((n-need)%3)
		return 0;
	return 1;
}

int main(){
	scanf("%I64d", &n);
	int ans=0;
	for(int i=1; i < 5000000; ++i)
		if(can(i))
			++ans;
	printf("%d\n", ans);
}