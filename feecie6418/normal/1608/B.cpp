#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
typedef long long ll;
int aa[100005];
void Solve(){
	int n,a,b;
	cin>>n>>a>>b;
	if(abs(a-b)>1)return puts("-1"),void();
	if(a+b>n-2)return puts("-1"),void();
	if(a==b){
		for(int i=1;i<=n;i++)aa[i]=i;
		for(int i=2,k=1;k<=a;k++,i+=2)swap(aa[i],aa[i+1]);
	}
	else {
		for(int i=1;i<=n;i++)aa[i]=i;
		for(int i=1,k=1;k<=max(a,b);k++,i+=2)swap(aa[i],aa[i+1]);
		if(a==b+1){
			for(int i=1;i<=n;i++)aa[i]=n-aa[i]+1;
		}
	}
	for(int i=1;i<=n;i++)cout<<aa[i]<<' ';
	puts("");
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--)Solve();
}