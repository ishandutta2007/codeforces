#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
int a,b,c,d,e,f;
int ans=0;
int main(){
	cin>>a>>b>>c>>d>>e>>f;
	for(int i=0;i<=min(a,d);i++){
		ans=max(ans,i*e+min(b,min(c,d-i))*f);
	}
	cout<<ans<<endl;
	return 0;
}