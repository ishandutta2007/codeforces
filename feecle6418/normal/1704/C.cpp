#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pr;
int n,L,a[100005],b[100005];
void Solve(){
	scanf("%d%d",&L,&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++)b[i]=a[i+1]-a[i]-1;
	b[n]=a[1]+L-a[n]-1;
	sort(b+1,b+n+1,greater<int>());
	int days=0,lef=0;
	for(int i=1;i<=n;i++){
		int cur=max(0,b[i]-2*days);
		if(!cur)continue;
		lef+=max(1,cur-1);
		if(cur>=3)days+=2;
		else days++;
	}
	cout<<L-lef<<'\n';
}
int main(){
	int t;
	cin>>t;
	while(t--)Solve();
}