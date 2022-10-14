#include<bits/stdc++.h>
using namespace std;
#define I inline int
#define ll long long int
#define FOR(i,a,b) for(int i=a;i<=b;i++)
const int N=2e5+1;
int T,n,m,q,len,s[N];
I gcd(int x,int y){return!y?x:gcd(y,x%y);}
ll ask(ll x){return (x/len)*s[len-1]+s[x%len];}
int main(){
	cin.tie(0);
	for(cin>>T;T--;){
    	cin>>n>>m>>q,len=n*m/gcd(n,m);
    	FOR(i,0,len-1)s[i]=(i%n%m)!=(i%m%n);
    	FOR(i,1,len-1)s[i]+=s[i-1];
    	for(ll l,r;q--;cout<<ask(r)-ask(l-1)<<' ')
    		cin>>l>>r;
    	cout<<'\n';
	}
	return 0;
}