#include<bits/stdc++.h>
using namespace std;
#define N 1205
typedef long long ll;
int n,t[N],T,a[N];
inline bool OK(int u){
	return u>=1&&t[a[u]]==(T&1);
}
bool check(int u){
	if(OK(u)&OK(u-1)&OK(u-2)){
		cout<<a[u-2]<<' '<<a[u-1]<<' '<<a[u]<<'\n';
		for(int j=u-2;j<=6*n-3*T;++j)a[j]=a[j+3];
		return true;
	}
	else return false;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=3*n;++i){
		int x;
		cin>>x;
		t[x]=1;
	}
	for(int i=1;i<=6*n;++i)a[i]=i;
	for(T=1;T<=2*n;++T){
		bool ok=false;
		for(int i=2,jb=0;i<=6*n-3*(T-1);++i){
			if(i%3!=1&&t[a[i]]^t[a[i-1]])jb=1;
			if(!ok&&jb)ok=check(i);	
		}
		for(int i=3;i<=6*n-3*(T-1);++i){
			if(!ok)ok=check(i);
		}
		if(!ok)exit(T);
	}
	return 0;
}