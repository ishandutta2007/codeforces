#include<bits/stdc++.h>
using namespace std;
int main(){
#ifdef flukehn
	freopen("a.in","r",stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a[4];
	while(cin>>a[0]>>a[1]>>a[2]>>a[3]){
		sort(a,a+4);
		int ans=0;
		if(a[2]<a[0]+a[1])ans=2;
		if(a[2]==a[0]+a[1])ans=1;
		if(a[3]<a[2]+a[1])ans|=2;
		if(a[3]==a[1]+a[2])ans|=1;
		if(ans>>1&1)puts("TRIANGLE");
		else if(ans)puts("SEGMENT");
		else puts("IMPOSSIBLE");
	}
}