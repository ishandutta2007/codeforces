#include <bits/stdc++.h>

using namespace std;

char inp[100005];
int sum[128][2];
long long ans[128];

int main(){
	scanf("%s", inp);
	for(int i=0; inp[i]; ++i){
		sum[inp[i]][i%2]++;
		ans[0] += sum[inp[i]][i%2];
		ans[1] += sum[inp[i]][(i+1)%2];
	}
	printf("%I64d %I64d\n", ans[1], ans[0]);
}