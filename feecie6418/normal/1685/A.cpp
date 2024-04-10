#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
const int mod=998244353;
int n,a[100005],b[100005];
void Solve(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n&1)return puts("NO"),void();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i+=2)b[i]=a[(i+1)/2];
	for(int i=2;i<=n;i+=2)b[i]=a[n/2+i/2];
	for(int i=1;i<=n;i++){
		if(b[i]==b[i%n+1])return puts("NO"),void();
	}
	puts("YES");
	for(int i=1;i<=n;i++)cout<<b[i]<<' ';
	puts("");
}
int main(){
	int t;
	cin>>t;
	while(t--)Solve(); 
}