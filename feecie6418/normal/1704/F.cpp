#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pr;
typedef long long ll;
const int mod=998244353;
int f[500005],n;
char a[500005];
void Solve(){
	scanf("%d%s",&n,a+1);
	int cA=0,cB=0;
	for(int i=1;i<=n;i++)cB+=(a[i]=='B');
	cA=n-cB;
	if(cA>cB)return puts("Alice"),void();
	if(cB>cA)return puts("Bob"),void();
	int ans=0;
	for(int i=1,j;i<=n;i=j+1){
		j=i;
		while(j<n&&a[j+1]!=a[j])j++;
		int len=j-i+1;
		while(len>=500)len-=34;
		ans^=f[len];
	}
	if(ans)puts("Alice");
	else puts("Bob");
}
int main(){
	for(int i=1;i<=500;i++){
		map<int,int> mp;
		for(int j=0;j+2<=i;j++)mp[f[j]^f[i-j-2]]=1;
		while(mp[f[i]])f[i]++;
	}
	int t;
	scanf("%d",&t);
	while(t--)Solve();
}