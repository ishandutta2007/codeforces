#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
int n,m;
char a[65][65];
void Solve(){
	scanf("%d%d",&n,&m);
	int cnt=0;
	for(int i=1;i<=n;i++){
		scanf("%s",a[i]+1);
		for(int j=1;j<=m;j++)cnt+=(a[i][j]=='A');
	}
	if(cnt==n*m)return puts("0"),void();
	if(cnt==0)return puts("MORTAL"),void();
	bool can1=0,can2=0,can3=0;
	cnt=0;
	for(int i=1;i<=m;i++)cnt+=(a[1][i]=='A');
	can1|=(cnt==m),can3|=cnt,cnt=0;
	for(int i=1;i<=m;i++)cnt+=(a[n][i]=='A');
	can1|=(cnt==m),can3|=cnt,cnt=0;
	for(int i=1;i<=n;i++)cnt+=(a[i][1]=='A');
	can1|=(cnt==n),can3|=cnt,cnt=0;
	for(int i=1;i<=n;i++)cnt+=(a[i][m]=='A');
	can1|=(cnt==n),can3|=cnt,cnt=0;
	can2|=(a[1][1]=='A'),can2|=(a[1][m]=='A'),can2|=(a[n][1]=='A'),can2|=(a[n][m]=='A');
	if(can1)return puts("1"),void();
	for(int i=1;i<=n;i++){
		cnt=0;
		for(int j=1;j<=m;j++)cnt+=(a[i][j]=='A');
		if(cnt==m)can2|=1;
	}
	for(int i=1;i<=m;i++){
		cnt=0;
		for(int j=1;j<=n;j++)cnt+=(a[j][i]=='A');
		if(cnt==n)can2|=1;
	}
	if(can2)return puts("2"),void();
	if(can3)return puts("3"),void();
	puts("4");
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--)Solve();
}