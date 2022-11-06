#include<bits/stdc++.h>
using namespace std;
const int N=2e5+11;
int a[N],b[N];
int n;
int chk(int m){
	int now=0;
	for(int i=0;i<n;++i){
		if(b[i]>=now&&now+1+a[i]>=m)++now;
	}
	return now>=m;
}
int work(){
	cin>>n;
	for(int i=0;i<n;++i)cin>>a[i]>>b[i];
	int l=1,r=n;
	while(l<r){
		int m=(l+r+1)/2;
		if(chk(m))l=m;
		else r=m-1;
	}
	return l;
}
int main(){
#ifdef flukehn
	freopen("a.in","r",stdin);
#endif
	ios::sync_with_stdio(0),cin.tie(0);
	int t;
	cin>>t;
	while(t--)cout<<work()<<"\n";
}