#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[205];
void Solve(){
	cin>>n;
	int s=0,flag=0;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),s+=a[i];
	for(int i=2;i<s;i++)if(s%i==0)flag=1;
	if(flag==1){
		cout<<n<<'\n';
		for(int i=1;i<=n;i++)cout<<i<<' ';
		puts("");
	}
	else {
		cout<<n-1<<'\n';
		int pos=0;
		for(int i=1;i<=n;i++){
			if(a[i]&1)pos=i;
		}
		for(int i=1;i<=n;i++)if(i!=pos)cout<<i<<' ';
		puts("");
	}
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--)Solve();
}