#include <bits/stdc++.h>

using namespace std;

int dp[100005][2];
int a[100005];

struct Fenwick{
	int a[100005];

	void update(int pos, int x){
		while(pos < 100003){
			a[pos]=max(a[pos], x);
			pos|=pos+1;
		}
	}

	int query(int pos){
		int ret=0;
		for(int i=pos; i >= 0; i=(i&(i+1))-1){
			ret=max(ret, a[i]);
		}
		return ret;
	}
} fenwick[2];

int num[100005];

int main(){
	int n;
	scanf("%d", &n);
	for(int i=0; i < n; ++i){
		scanf("%d", a+i);
	}
	int ans=0;
	for(int i=0; i < 2; ++i){
		for(int j=0; j < n; ++j){
			int cur=i?a[j]:(100001-a[n-1-j]);
			dp[j][i]=fenwick[i].query(cur-1)+1;
			fenwick[i].update(cur, dp[j][i]);
			ans=max(ans, dp[j][i]+1);
		}
	}
	for(int i=0; i*2 < n; ++i)
		swap(dp[i][0], dp[n-i-1][0]);
	for(int i=0; i < n; ++i){
		if(dp[i][0]+dp[i][1] == ans)
			++num[dp[i][0]];
	}
	for(int i=0; i < n; ++i){
		if(dp[i][0]+dp[i][1] == ans){
			if(num[dp[i][0]] == 1)
				printf("3");
			else
				printf("2");
		}
		else
			printf("1");
	}
	printf("\n");
}