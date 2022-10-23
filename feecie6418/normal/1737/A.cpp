#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
mt19937_64 rng(time(0));
int rnd(int l,int r){
	return l+rng()%(r-l+1);
}
char a[205];
void Solve(){
	int cnt[30]={0},n,k;
	cin>>n>>k>>a+1;
	for(int i=1;i<=n;i++)cnt[a[i]-'a']++;
	for(int i=1;i<=k;i++){
		int j=0;
		while(j<n/k&&cnt[j])cnt[j]--,j++;
		putchar('a'+j);
	}
	puts("");
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--)Solve();
}