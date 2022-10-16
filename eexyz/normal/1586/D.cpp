#include<bits/stdc++.h>
using namespace std;
#define N 1000005
#define ls k<<1
#define rs k<<1|1
#define mid (l+r>>1)
char a[N];
int n,i,j,val,pos[N],y,b,q,c,is[N],T,l,r,s,fl;
int check(int x){
	for(i=2;i<x;++i){
		if(x%i==0)return 1;
	}
	return 0;
}
int m,vis[1000005],x[N];
int main(){
	cin>>n;
	for(i=2;i<=n;++i){
		cout<<"? ";
		for(j=1;j<n;++j)cout<<i<<" ";
		cout<<1<<"\n";cout.flush();
		cin>>x[i];
		if(x[i]){
			val=i;
		}
	}
	if(!val)val=1;
	pos[n]=val;
	for(i=1;i<=n;++i){
		if(i==val)continue;
		cout<<"? ";
		for(j=1;j<n;++j){
			cout<<val<<" ";
		}
		cout<<i<<"\n";cout.flush();
		cin>>x[i];
		pos[x[i]]=i;
	}
	cout<<"! ";for(i=1;i<=n;++i)cout<<pos[i]<<" ";
}