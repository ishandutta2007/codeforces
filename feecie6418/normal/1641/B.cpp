#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
int a[1000005],n,ans[1000005],tmp[1000005];
struct Oper{
	int x,y;
}b[1000005];
int qc;
void Solve(){
	ans[0]=qc=0;
	scanf("%d",&n);
	map<int,int> cnt;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=n;i>=1;i--)cnt[a[i]]^=1;
	for(auto i:cnt)if(i.second)return puts("-1"),void();
	int N=n,curlen=0;
	while(N){
		int j=2;
		while(a[j]!=a[1])j++;
		curlen+=j;
		//cout<<"FIR:"<<curlen<<'\n';
		for(int k=2;k<j;k++){
			b[++qc]={curlen,a[k]};
			curlen++;
		}
		//cout<<"SEC:"<<curlen<<'\n';
		ans[++ans[0]]=2*(j-1);
		int O=0;
		for(int i=j-1;i>1;i--)tmp[++O]=a[i];
		for(int i=j+1;i<=N;i++)tmp[++O]=a[i];
		N-=2;
		for(int i=1;i<=N;i++)a[i]=tmp[i];
	}
	cout<<qc<<'\n';
	for(int i=1;i<=qc;i++)printf("%d %d\n",b[i].x,b[i].y);
	cout<<ans[0]<<'\n';
	for(int i=1;i<=ans[0];i++)cout<<ans[i]<<' ';
	puts("");
}
int main(){
	int t;
	cin>>t;
	while(t--)Solve();
}