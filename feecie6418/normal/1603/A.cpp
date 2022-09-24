#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
int n,a[100005];
void Solve(){
	scanf("%d",&n);
	bool ok=1;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		int flag=0;
		for(int j=2;j<=i+1;j++){
			if(a[i]%j){
				flag=1;
				break;
			}
		}
		if(!flag){
			ok=0;
		}
	}
	if(ok)puts("YES");
	else puts("NO");
} 
int main(){
	int t;
	scanf("%d",&t);
	while(t--)Solve();
}