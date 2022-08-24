#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
ll w[1001];
int a[1001];
int ap[1001];
int s[1001];
int ptr=0;
ll ans=0;
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i=1; i<=n ;i++) cin >> w[i];
	for(int i=1; i<=m ;i++){
		cin >> a[i];
		if(!ap[a[i]]){
			ap[a[i]]=1;
			s[++ptr]=a[i];
		}
	}
	for(int i=1; i<=n ;i++){
		if(!ap[i]) s[++ptr]=i;
	}
	for(int i=1; i<=m ;i++){
		int p;
		for(int j=1; j<=n ;j++){
			if(s[j]==a[i]){
				p=j;break;
			}
		}
		for(int j=p-1; j>=1 ;j--){
			ans+=w[s[j]];
			swap(s[j],s[j+1]);
		}
	}
	cout << ans << endl;
}