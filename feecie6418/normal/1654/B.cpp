#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
typedef long long ll;
char a[200005];
void Solve(){
	cin>>a+1;
	int n=strlen(a+1);
	int cnt[130]={0},mn=n;
	for(int i=n;i>=1;i--){
		++cnt[a[i]];
		if(cnt[a[i]]==1)mn=i;
	}
	for(int i=mn;i<=n;i++)cout<<a[i];
	puts("");
}
int main(){
	int t;
	cin>>t;
	while(t--)Solve();
}