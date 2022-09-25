#include<bits/stdc++.h>
using namespace std;
#define N 500050
typedef long long ll;
int Q,n,to[N],opt[N],x[N],y[N],a[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	for(int i=1;i<=500000;++i)to[i]=i;
	cin>>Q;
	for(int i=Q;i>=1;--i){
		cin>>opt[i]>>x[i];
		if(opt[i]==2)cin>>y[i];
	}
	for(int i=1;i<=Q;++i){
		if(opt[i]==1){
			a[++n]=to[x[i]];
		}
		else{
			to[x[i]]=to[y[i]];
		}
	}
	while(n)cout<<a[n--]<<' ';
	return 0;
}