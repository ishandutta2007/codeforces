#include<bits/stdc++.h>
using namespace std;
#define N 1000005
int main(){
	int n;
	scanf("%d",&n);
	int a[N];
	for(int i=0;i<n;i++)
	scanf("%d",&a[i]);
	sort(a,a+n);
	int now=1;
	for(int i=0;i<n;i++){
		if(a[i]>=now)
		now++;
	}
	printf("%d\n",now);
}