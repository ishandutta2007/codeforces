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

int always[205];
int chooseFrom[205];
int a[205];

int main(){
	int n, k;
	scanf("%d%d", &n, &k);
	for(int i=0; i < n; ++i)
		scanf("%d", a+i);
	int ans=-10000000;
	for(int l=0; l < n; ++l)
		for(int r=l+1; r <= n; ++r){
			for(int i=l; i < r; ++i)
				always[i-l]=a[i];
			int p=0;
			for(int i=0; i < l; ++i)
				chooseFrom[p++]=a[i];
			for(int i=r; i < n; ++i)
				chooseFrom[p++]=a[i];
			sort(always, always+(r-l));
			sort(chooseFrom, chooseFrom+p);
			int sum=0;
			for(int i=0; i < r-l; ++i)
				sum += always[i];
			for(int i=0; i < k && i < p && i < r-l; ++i){
				if(always[i] < chooseFrom[p-i-1])
					sum += chooseFrom[p-i-1]-always[i];
			}
			if(sum > ans)
				ans=sum;
		}
	printf("%d\n", ans);
	return 0;
}