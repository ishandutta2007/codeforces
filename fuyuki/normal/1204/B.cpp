#include<iostream>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
int n,l,r,sum,ans1,ans2,now=1;
int main(){
	cin>>n>>l>>r;
	FOR(i,1,l)sum+=now,now<<=1;
	ans1=ans2=sum;
	FOR(i,l+1,n)ans1++;
	FOR(i,l+1,r)ans2+=now,now<<=1;
	FOR(i,r+1,n)ans2+=now>>1;
	cout<<ans1<<' '<<ans2;
}