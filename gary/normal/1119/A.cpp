#include<bits/stdc++.h>
using namespace std;
map<int,int> C;
int up[300001];
int n,c[300001];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
		if(!C[c[i]]){
			C[c[i]]=i;
		}
	}
	int ans=-0x3f3f3f3f;
	for(int i=1;i<=n;i++){
	if(ans+i>=n) break;
		if(C[c[i]]==i){
			int j;
			for(j=n;j>=i;j--){
				if(c[j]!=c[i]){
					break;
				}
			}
			ans=max(ans,j-i);
		}
	}
	printf("%d\n",ans);
	return 0;
}