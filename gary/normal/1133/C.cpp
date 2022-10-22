#include<bits/stdc++.h>
using namespace std;
int n,a[200001];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	int ans=0,l=1,t=1;
	for(l=1;l<=n;l++){
		while(a[t]-a[l]<=5&&t<=n){
			t++;
		}
		t--;
		ans=max(ans,t-l+1);
	}
	printf("%d\n",ans);
	return 0;
}