#include<bits/stdc++.h>
using namespace std;
#define N 233
typedef long long ll;
int n,a[N];
bool check(int D,int x){
	for(int i=1;i<=n;++i){
		if(a[i]==x||a[i]-D==x||a[i]+D==x)continue;
		return false;
	}
	return true;	
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];	
	}
	for(int D=0;D<=200;++D){
		for(int x=-200;x<=200;++x){
			if(check(D,x)){
				cout<<D<<'\n';
				return 0;
			}	
		}	
	}
	cout<<-1<<'\n';
	return 0;
}