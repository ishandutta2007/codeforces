#include<bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long ll;
int n,K,a[N],b[N];
void Solve(){
	cin>>n>>K;
	if(n==4&&K==3){
		cout<<-1<<'\n';
		return;
	}
	for(int i=0;i<n/2;++i){
		a[i]=i,b[i]=((n-1)^i);
	}
	if(K<n-1){
		if(K){
			for(int i=0;i<n/2;++i){
				if(a[i]==K){
					swap(a[i],a[0]);
					break;
				}
				if(b[i]==K){
					swap(b[i],a[0]);
					break;
				}
			}
		}
	}
	else{
		swap(a[0],b[1]);
		swap(b[3],a[1]);
	}
	for(int i=0;i<n/2;++i){
		cout<<a[i]<<' '<<b[i]<<'\n';
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}