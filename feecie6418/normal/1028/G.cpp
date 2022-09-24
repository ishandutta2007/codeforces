#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
typedef vector<ll> ve;
const ll N=10000,M=10004205361450474;
ll f[10][10005];
int Query(ve v){
	while(v.back()>M)v.pop_back();
	cout<<v.size()<<' ';
	for(ll i:v)cout<<i<<' ';
	cout<<endl;
	int res;
	cin>>res;
	if(res==-1)exit(0);
	return res;
}
int main(){
	for(int j=1;j<=N;j++)f[1][j]=j;
	for(int i=2;i<=5;i++){
		for(int j=1;j<=N;j++){
			f[i][j]=f[i-1][j];
			ll t=j;
			for(int k=1;k<=j;k++){
				t+=f[i-1][t]+1,t=min(t,N);
				f[i][j]+=1+f[i-1][t];
			}
		}
	}
	ll L=1;
	for(int i=5;i>=1;i--){
		ll t=L;
		ve v;
		for(int k=1;k<=min(L,N);k++)t+=f[i-1][min(t,N)],v.push_back(t),t++;
		int res=Query(v);
		if(res)L=v[res-1]+1;
	}
}