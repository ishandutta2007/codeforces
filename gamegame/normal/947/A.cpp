#include<iostream>
using namespace std;
int n;
bool np[4000001];
int bpf[4000001];
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=2; i<=n ;i++){
		if(np[i]) continue;
		for(int j=2*i; j<=n ;j+=i){
			np[j]=true;
			bpf[j]=i;
		}
	}
	int ans=n;
	for(int i=n-bpf[n]+1; i<=n ;i++){
		if(bpf[i]!=0) ans=min(ans,i-bpf[i]+1);
	}
	cout << ans <<endl;
}