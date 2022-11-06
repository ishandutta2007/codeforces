#include<bits/stdc++.h>
using namespace std;

int n;
int a[11];
int chk(){
	if(a[0]==0)return 1;
	for(int i=1;i<n;++i)
		if(a[i]==a[i-1])return 1;
	set<int> S;
	for(int i=1;i<(1<<n);++i){
		int tot=0;
		for(int j=0;j<n;++j)
			if(i>>j&1)tot+=a[j];
		if(S.count(tot))return 1;
		S.insert(tot);
	}
	return 0;
}
int main(){
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=0;i<n;++i){
			cin>>a[i];
			a[i]=abs(a[i]);
		}
		sort(a,a+n);
		if(chk())cout<<"YES\n";
		else cout<<"NO\n";
	}
}