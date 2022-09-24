#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
int n,m,s[1000005];
void Solve(){
	scanf("%d%d",&n,&m);
	for(int i=1,x;i<=n;i++)scanf("%d",&x),s[x]++;
	for(int i=1;i<=m;i++)s[i]=s[i-1]+s[i];
	bool fl=1;
	for(int i=1;i<=m;i++){
		if(s[i]-s[i-1]==0)continue;
		for(int j=i,t=1;j<=m;j+=i,t++){
			int l=j,r=min(j+i-1,m);
			if(s[r]-s[l-1]>0&&s[t]-s[t-1]==0){
				fl=0;
			}
		}
	}
	if(fl)puts("Yes");
	else puts("No");
	for(int i=1;i<=m;i++)s[i]=0;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--)Solve();
}