#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,a,b,c;
	cin>>n>>a>>b>>c;
	if(n==1)cout<<"0";
	else cout<<min(a,b)+(n-2)*min(min(a,b),c);
}