#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=a;i<=b;i++)
const int N=2048;
int n,m,k,B,ans,d,tag[N];
int ask(int p){
	static string tmp;
	cout<<"? "<<p<<'\n',cout.flush();
	return cin>>tmp,tmp=="Y";
}
int nxt(int x){return (x<=0)-x;}
void query(int p){
	FOR(i,p*B+1,(p+1)*B)if(!tag[i]&&ask(i))
		tag[i]=1,ans--;
}
int main(){
	cin>>n>>k,B=max(1,k/2),m=n/B,ans=n;
	FOR(i,0,n/k-1){
		if(i)cout<<"R\n",cout.flush(),d=0;
		FOR(j,1,m)query((i+d+m)%m),d=(d<=0)-d;
	}
	cout<<"! "<<ans<<'\n',cout.flush();
	return 0;
}