#include <bits/stdc++.h>
using namespace std;

int n;
int arr[105];

int main(){
	int TC;
	scanf("%d",&TC);
	while(TC--){
		scanf("%d",&n);
		for (int x=0;x<n;x++) scanf("%d",&arr[x]);
		sort(arr,arr+n);
		for (int x=0;x<n;x++) printf("%d ",arr[x]);
		printf("\n");
		for (int x=0;x<n;x++) scanf("%d",&arr[x]);
		sort(arr,arr+n);
		for (int x=0;x<n;x++) printf("%d ",arr[x]);
		printf("\n");
	}
}