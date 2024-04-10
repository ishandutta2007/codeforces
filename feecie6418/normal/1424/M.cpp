#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
int n,m,d[35],ans[35],is[35];
vector<int> g[35];
string a[1000005];
char str[105];
int main(){
	cin>>n>>m;
	for(int I=1;I<=n;I++){
		int i;
		scanf("%d",&i);
		for(int j=1;j<=m;j++)scanf("%s",str),a[i*m+j]=str;
	}
	for(int i=1;i<=n*m;i++)for(char j:a[i])is[j-'a'+1]=1;
	for(int i=2;i<=n*m;i++){
		int s=0,t=0;
		while(s<a[i-1].size()&&t<a[i].size()&&a[i-1][s]==a[i][t])s++,t++;
		if(s<a[i-1].size()&&t<a[i].size())g[a[i-1][s]-'a'+1].push_back(a[i][t]-'a'+1);
		else if(a[i-1].size()>a[i].size())return puts("IMPOSSIBLE"),0;
	}
	queue<int> q;
	for(int i=1;i<=26;i++)for(int j:g[i])d[j]++;
	for(int i=1;i<=26;i++)if(!d[i]&&is[i])q.push(i);
	int cnt=0;
	for(int i=1;i<=26;i++)if(is[i])cnt++;
	while(!q.empty()){
		int x=q.front();
		q.pop(),ans[++ans[0]]=x;
		for(int y:g[x])if(!--d[y])q.push(y);
	}
	if(ans[0]^cnt)return puts("IMPOSSIBLE"),0;
	for(int i=1;i<=cnt;i++)cout<<(char)('a'+ans[i]-1);
	return 0;
}