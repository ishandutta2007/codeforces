#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
typedef vector<int> perm;
int f[100005],n,a[100005];
void Solve(){
	scanf("%d",&n);
	map<int,int> lst;
	lst[0]=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]),a[i]^=a[i-1];
		f[i]=f[i-1];
		if(lst.count(a[i])){
			f[i]=max(f[i],f[lst[a[i]]]+1);
		}
		lst[a[i]]=i;
	}
	cout<<n-f[n]<<'\n';
	lst.clear();
	for(int i=0;i<=n;i++)f[i]=a[i]=0;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--)Solve();
}