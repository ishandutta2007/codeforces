#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cstring>
#include<string>
using namespace std;
string x[25],y[25];
int n,m,q; 
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>x[i];
	for(int j=1;j<=m;j++)cin>>y[j];
	cin>>q;
	while(q--){
		int u;
		cin>>u;
		cout<<x[(u%n?u%n:n)]<<y[(u%m?u%m:m)]<<endl;
	} 
}