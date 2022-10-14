#include<bits/stdc++.h>
using namespace std;
#define I inline int
#define V inline void
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
const int N=1e5+1;
int n,m,tot,ans=1,tag[N],pri[N];
V input(){cin>>n,m=sqrt(n);}
V init(){
	FOR(i,2,n){
		if(!tag[i])pri[++tot]=i;
		FOR(j,1,tot){
			if(i*pri[j]>n)break;
			tag[i*pri[j]]=1;
			if(i%pri[j]==0)break;
		}
	}
}
V del(int x,int out=0){cout<<"B "<<x<<endl,cin>>out;}
I count(int x,int out=0){return cout<<"A "<<x<<endl,cin>>out,out;}
V solve(int x){for(int p=1;n/p/x;ans*=x)if(!count(p*=x))return;}
V work(int p=0){
	FOR(i,1,tot)if(pri[i]<=m)del(pri[i]);
	FOR(i,1,tot)if(pri[i]<=m)solve(pri[p=i]);
	for(m=sqrt(tot);pri[tot]>n/ans;)tot--;
	if(ans==1){
		for(m=sqrt(tot);pri[tot]>n/ans;)tot--;
		for(int l=p+1,r,now=count(1);l<=tot;l=r+1){
			r=min(tot,l+m);
			FOR(i,l,r)del(pri[i]),now--;
			if(count(1)>now){
				FOR(i,l,r)if(count(pri[i])){
					ans*=pri[i];break;
				}
				break;
			}
		}
	}
	else FOR(i,p+1,tot)if(count(pri[i])>=2)ans*=pri[i];
	cout<<"C "<<ans<<endl;
}
int main(){
	input();
	init();
	work();
	return 0;
}