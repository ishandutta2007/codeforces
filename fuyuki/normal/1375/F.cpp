#include<bits/stdc++.h>
using namespace std;
#define I inline int
#define V inline void
#define ll long long int
#define FOR(i,a,b) for(int i=a;i<=b;i++)
const int N=3e6+1,sgn[2]={1,-1},INF=0x3f3f3f3f;
int t[4],p;ll a[4];
I cmp(int x,int y){return a[x]<a[y];}
V input(){FOR(i,1,3)cin>>a[i],t[i]=i;}
V init(){sort(t+1,t+1+3,cmp);}
V work(){
	cout<<"First"<<endl,cout<<a[t[3]]-a[t[1]]<<endl,cin>>p;
	if(p==t[1]){
		cout<<a[t[3]]-a[t[2]]<<endl;
		cin>>p;
		cout<<a[t[3]]-a[t[2]]<<endl;
	}
	else{
		a[p]+=a[t[3]]-a[t[1]],sort(t+1,t+1+3,cmp);
		cout<<2ll*a[t[3]]-a[t[1]]-a[t[2]]<<endl;
		cin>>p,a[p]+=2ll*a[t[3]]-a[t[1]]-a[t[2]];
		sort(t+1,t+1+3,cmp),cout<<a[t[3]]-a[t[2]]<<endl;
	}
}
int main(){
	input();
	init();
	work();
	return 0;
}