#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <fstream>
using namespace std;
int num[100005];
int main(){
	int n;
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&num[i]);
	}
	int a=0,ans=1000000;
	sort(num,num+n);
	for(int i=0;i<n;i++){
		a+=i;
		a+=n-(upper_bound(num,num+n,num[i]*2)-num);
		ans=min(ans,a);
		a=0;
	}
	printf("%d\n",ans);
	return 0;
}