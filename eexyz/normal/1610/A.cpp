#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 500005
#define py cout<<"YES\n"
#define pn cout<<"NO\n";
vector<int>son[N];
void dfs(int now,int fat){
	for(int T,i=0;i<son[now].size();++i)
		if((T=son[now][i])!=fat)dfs(T,now);
}
int T,n,i,j,x,y,m,a[N];
int main(){
	T=1;
	cin>>T;
	while(T--){
		cin>>n>>m;
		if(n!=1&&m!=1)cout<<"2\n";
		else if(n==1&&m==1)cout<<"0\n";
		else cout<<"1\n";
	}
}