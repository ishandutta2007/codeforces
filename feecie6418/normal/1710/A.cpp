#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
const int mod=1e9+7,N=1e6;
typedef long long ll;
int n,m,k,a[100005];
bool Check(int n,int m){
	ll sum=0;
	bool all2=1;
	for(int i=1;i<=k;i++){
		int can=a[i]/m;
		if(can<2)continue;
		sum+=can;
		if(can!=2)all2=0;
	}
	if(sum<n)return 0;
	if(all2&&n%2==1)return 0;
	return 1;
}
void Solve(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=k;i++)scanf("%d",&a[i]);
	if(Check(n,m))return puts("Yes"),void(); 
	if(Check(m,n))return puts("Yes"),void(); 
	puts("No");
}
int main(){
	int t;
	cin>>t;
	while(t--)Solve();
}