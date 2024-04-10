#include<bits/stdc++.h>
using namespace std;
#define N 1000005
int T,n,k,i,gg,hh,f[N],j,l[N],to[N],L,R,r[N],v[N],mn,mx,pos;
int ask(int x){
	cout<<"? "<<x<<"\n";cout.flush();
	cin>>x;
	return x;
}
int main(){
	cin>>T;
	while(T--){
	cin>>n;
	for(i=1;i<=n;++i)f[i]=0;
	for(i=1;i<=n;++i){
		if(!f[i]){
			gg=ask(i);
			hh=ask(i);
			f[gg]=hh;gg=hh;
			while(!f[gg]){
				hh=ask(i);
				f[gg]=hh;
				gg=hh;
			}
		}
	}
	cout<<"! ";
	for(i=1;i<=n;++i)cout<<f[i]<<' ';cout<<"\n";cout.flush();
	}
}