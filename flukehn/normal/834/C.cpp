#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		int A,B;
		scanf("%d%d",&A,&B);
		long long t = 1LL * A * B;
		int mid = pow(t, 0.33333333333333333333333) + 0.9;
		if ( mid && A % mid == 0 && B % mid == 0)
			puts("YES");
		else puts("NO");
	}
}