#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
const int mod=1e9+7;
int n,m;
void Solve(){
	scanf("%d%d",&n,&m);
	if(n>m){
		puts("No");
		return ;
	}
	if(n&1){
		puts("Yes");
		for(int i=1;i<n;i++)cout<<"1 ";
		cout<<m-n+1<<'\n';
		return ;
	}
	if(m&1){
		puts("No");
		return ;
	}
	puts("Yes");
	for(int i=1;i<=n-2;i++)cout<<"1 ";
	cout<<(m-n+2)/2<<' '<<(m-n+2)/2<<'\n';
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--)Solve(); 
}