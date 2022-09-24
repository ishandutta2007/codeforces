#include<bits/stdc++.h>
using namespace std;
int n,cnt[3][2];
char a[3][300005];
string t[300005];
void Print(int x,int y,int z){
	for(int i=0;i<=n;i++)t[i].clear();
	int j=1;
	for(int i=1;i<=n;i++){
		int lstj=j;
		while(a[x][j]!=z+'0')j++;
		for(int k=lstj;k<j;k++)t[i-1].push_back(a[x][k]);
		j++;
	}
	for(int k=j;k<=2*n;k++)t[n].push_back(a[x][k]);
	j=1;
	for(int i=1;i<=n;i++){
		int lstj=j;
		while(a[y][j]!=z+'0')j++;
		for(int k=lstj;k<j;k++)t[i-1].push_back(a[y][k]);
		j++;
	}
	for(int k=j;k<=2*n;k++)t[n].push_back(a[y][k]);
	for(int i=0;i<=n;i++){
		if(i)cout<<z;
		cout<<t[i];
	}
	puts("");
}
void Solve(){
	memset(cnt,0,sizeof(cnt));
	scanf("%d%s%s%s",&n,a[0]+1,a[1]+1,a[2]+1);
	for(int i=0;i<3;i++){
		for(int j=1;j<=2*n;j++){
			cnt[i][a[i][j]-'0']++;
		}
	}
	for(int p=0;p<3;p++){
		for(int q=p+1;q<3;q++){
			if(cnt[p][0]>=n&&cnt[q][0]>=n)return Print(p,q,0);
			if(cnt[p][1]>=n&&cnt[q][1]>=n)return Print(p,q,1);
		}
	}
}
int main(){
	int t;
	cin>>t;
	while(t--)Solve();
}