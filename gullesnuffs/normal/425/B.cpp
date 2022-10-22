#include <cstdio>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <stack>
#include <iostream>
using namespace std;

int a[105][105];
int bit[105];
int t[105][2];

int main(){
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for(int i=0; i < n; ++i)
		for(int j=0; j < m; ++j)
			scanf("%d", a[i]+j);
	if(m > 2*k){
		int ans=0;
		for(int i=0; i < n; ++i){
			int b[2]={0, 0};
			for(int j=0; j < m; ++j){
				if(a[i][j] == a[0][j])
					++b[0];
				else
					++b[1];
			}
			int x=(b[0]>b[1]);
			for(int j=0; j < m; ++j){
				if(a[i][j]^a[0][j]^x)
					++t[j][0];
				else
					++t[j][1];
			}
		}
		for(int j=0; j < m; ++j)
			ans += min(t[j][0], t[j][1]);
		if(ans > k)
			printf("-1\n");
		else
			printf("%d\n", ans);
		return 0;
	}
	for(int i=0; i < n; ++i)
		for(int j=0; j < m; ++j)
			bit[i]|=(a[i][j]<<j);
	int ans=k+1;
	for(int i=0; i < (1<<m); ++i){
		int sum=0;
		for(int j=0; j < n; ++j){
			int v=__builtin_popcount(bit[j]^i);
			sum += min(v, m-v);
			if(sum >= ans)
				break;
		}
		if(sum < ans)
			ans=sum;
	}
	if(ans > k)
		printf("-1\n");
	else
		printf("%d\n", ans);
	return 0;
}