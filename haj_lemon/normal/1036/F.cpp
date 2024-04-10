#include<bits/stdc++.h>
#define ll long long
#define maxi 60
#define eps 1e-10
using namespace std;
ll t,a[70],n,nn,miu[70],su[70],ns;
bool co(ll x,ll y,ll z){
	ll d,nx;
	if (z%2==1){d=z/2;z-=d;nx=x;}
	else{d=z/2;z-=d;nx=x;}
	while (z){
		if (z%2==1) y=y/x;
		z/=2;if (z!=0)x=x*x;
	}
	while (d){
		if (d%2==1) y=y/nx;
		d/=2;if (d!=0)nx=nx*nx;
	}
	if (y!=0) return true;return false;
}
ll co(ll x,ll y){
	ll z=(pow(y,1.0/x)-0.1);
	while (co(z+1,y,x)) z++;
	return z-1;
}
int main(){
	scanf("%d",&t);
	for (int i=2;i<=maxi;i++){
		if (a[i]==0)su[++ns]=i,miu[i]=-1;
		for (int j=1;j<=ns&&i*su[j]<=maxi;j++){
			a[i*su[j]]=1;if (i%su[j]==0){miu[i*su[j]]=0;break;}
			miu[i*su[j]]=miu[i]*miu[su[j]];
		}
	}
	while (t--){
		cin>>n;nn=n;
		for (int i=2;i<=maxi;i++)nn+=miu[i]*co(i,n);
		cout<<nn-1<<endl;
	}
	return 0;
}
/*
3
2
999999999999933299
*/