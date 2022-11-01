#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 100010
int n,c[N];
void Solve(){
	int n,a,b;
	cin>>n>>a>>b;
	if(a+b>n-2||abs(a-b)>1){
		cout<<-1<<'\n';
		return;
	}
	if(a==b){
		int l=1,r=n,j=1;
		for(int i=1;i<=a;++i){
			c[j++]=l++;
			c[j++]=r--;
		}
		while(j<=n)c[j++]=l++;
	}
	else if(a==b+1){
		int l=1,r=n,j=1;
		for(int i=1;i<=b;++i){
			c[j++]=l++;
			c[j++]=r--;
		}
		c[j++]=l++;
		while(j<=n)c[j++]=r--;	
	}
	else{
		int l=1,r=n,j=1;
		for(int i=1;i<=a;++i){
			c[j++]=r--;
			c[j++]=l++;
		}
		c[j++]=r--;
		while(j<=n)c[j++]=l++;	
	}
	for(int i=1;i<=n;++i){
		cout<<c[i]<<' ';
	}
	cout<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}