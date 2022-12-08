#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10;
map<int,int>S,P;
int a[N];
int main() {
	int T,n,x;
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d",&n,&x);
		S.clear();
		P.clear();
		int M=0;
		for(int i=1;i<=n;i++) {
			scanf("%d",a+i);
			M=max(M,a[i]);
			S[a[i]]++;
		}
		sort(a+1,a+n+1);
		int ans=0;
		for(int i=1;i<=n;i++) {
			if(P[a[i]]) {
				P[a[i]]--;
				continue;
			}
			if(1ll*a[i]*x<=M&&S[a[i]*x]) {
				S[a[i]]--;
				S[a[i]*x]--;
				P[a[i]*x]++;
			} else ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}