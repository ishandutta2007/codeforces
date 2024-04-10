#include<iostream>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
int a[101],t[3][3]={{-1,3,4},{3,-1,-1},{4,-1,-1}};
int main(){
	int n,ans=0;
	cin>>n;
	FOR(i,1,n)cin>>a[i],a[i]--;
	FOR(i,2,n)
		if(~t[a[i]][a[i-1]])ans+=t[a[i]][a[i-1]],ans-=i>2&&a[i]==1&&a[i-2]==2;
		else return cout<<"Infinite",0;
	cout<<"Finite\n"<<ans;
	return 0;
}