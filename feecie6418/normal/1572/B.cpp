#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
int n,a[300005],cnt=0;
vector<int> ans;
void Do(int x){
	ans.push_back(x),assert(++cnt<=n);
	a[x]=a[x+1]=a[x+2]=(a[x]^a[x+1]^a[x+2]);
}
void Solve(){
	scanf("%d",&n),cnt=0;
	int sum=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	if(sum%2==1||sum==n){
		puts("NO");ans.clear();
		return ;
	}
	for(int i=1;i<=n;){
		if(!a[i]){
			i++;
			continue;
		}
		int j=i;
		while(j<n&&a[j+1])j++;
		if((j-i+1)%2==0){
			if(j!=n){
				for(int k=j-1;k>=i;k-=2)Do(k);
			}
			else {
				for(int k=i-1;k<=j-2;k+=2)Do(k);
			}
			i=j+1;
			continue;
		}
		int k;
		lab:
		for(k=j;k<=n-2&&!a[k+1]&&!a[k+2];k+=2){
			Do(k);
		}
		while(k<n&&a[k+1])k++;
		if(k==n){
			if(i==1){
				puts("NO");ans.clear();
				return ;
			}
			for(int j=i-1;j<=k-2;j+=2)Do(j);
			break;
		}
		if((k-i+1)%2==0){
			for(int j=k-1;j>=i;j-=2)Do(j);
			i=k+1;
			continue;
		}
		if(a[k+2]==1){
			for(int j=k;j>=i;j-=2)Do(j);
			i=k+1;
			continue;
		}
		j=k;
		goto lab;
	}
	for(int i=1;i<=n;i++)assert(!a[i]);
	puts("YES");
	cout<<ans.size()<<'\n';
	for(int i:ans)cout<<i<<' ';
	puts("");
	ans.clear();
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--)Solve();
}