#include<bits/stdc++.h>
using namespace std;
#define N 1000005
#define ls k<<1
#define rs k<<1|1
#define mid (l+r>>1)
int n,i,j,x,y,a[N],T,l,r,s,fl;
int check(int x){
	for(i=2;i<x;++i){
		if(x%i==0)return 1;
	}
	return 0;
}
int main(){
	ios::sync_with_stdio(0);
	cin>>T;
	while(T--){
		s=0;cin>>n;
		for(i=1;i<=n;++i)cin>>a[i],s+=a[i];
		if(check(s)){
			cout<<n<<"\n";
			for(i=1;i<=n;++i)cout<<i<<" ";
			cout<<"\n";
		}
		else{
			cout<<n-1<<"\n";
			for(fl=i=1;i<=n;++i){
				if(fl&&(a[i]&1))fl=0;
				else cout<<i<<" ";
			}
		}
		cout<<"\n";
	}
}