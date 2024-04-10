#include<bits/stdc++.h>
using namespace std;
int a[200005],n,K,cnt[200005],s[200005];
void Solve(){
	scanf("%d%d",&n,&K);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),cnt[a[i]]++;
	int mn=1e9,mnl=0,mnr=0;
	for(int i=1,j=0,curs=0;i<=n;i++){
		j=max(j,i-1);
		while(j+1<=n&&curs-(n-curs)<K){
			j++;
			curs+=cnt[j];
		}
		if(j==n&&curs-(n-curs)<K)break;
		if(j-i<mn)mn=j-i,mnl=i,mnr=j;
		curs-=cnt[i];
	}
	cout<<mnl<<' '<<mnr<<'\n';
	for(int i=1,cur=0,lst=1;i<=n;i++){
		if(mnl<=a[i]&&a[i]<=mnr)s[i]=s[i-1]+1;
		else s[i]=s[i-1]-1;
		if((cur+1!=K&&s[i]==cur+1)||i==n){
			cout<<lst<<' '<<i<<'\n';
			cur++;
			lst=i+1;
		}
	}
	for(int i=1;i<=n;i++)cnt[i]=s[i]=0;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--)Solve();
}