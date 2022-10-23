#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr; 
int n,a[200005],mus[200005];
pr b[200005];
void Solve(){
	cin>>n;
	for(int i=1;i<=n;i++)mus[i]=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		int w=max(0,a[i-1]-a[i]);
		b[i]=pr(w,i);
	}
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++)cout<<b[i].second<<' ';
	puts("");
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--)Solve();
}