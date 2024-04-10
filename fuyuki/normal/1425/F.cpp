#include<bits/stdc++.h>
using namespace std;
#define I inline int
#define V inline void
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
const int N=1e3+1,mod=1e9+7;
int n,sum;
int a[N],s[N];
I ask(int l,int r){
	cout<<"? "<<l<<' '<<r<<endl;
	cin>>l;
	return l;
//	return s[r]-s[l-1];
}
V input(){
	cin>>n;
//	FOR(i,1,n)cin>>s[i],s[i]+=s[i-1];
}
V init(){
	FOR(i,2,n)a[i]=ask(1,i);
	a[1]=a[3]-ask(2,3);
	ROF(i,n,2)a[i]=a[i]-a[i-1];
}
V work(){
	cout<<"! ";
	FOR(i,1,n)cout<<a[i]<<' ';
	cout<<endl;
//	FOR(i,1,n)assert(a[i]==s[i]-s[i-1]);
}
int main(){
//	freopen("test.in","r",stdin);
	input();
	init();
	work();
	return 0;
}