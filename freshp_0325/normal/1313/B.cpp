#include<cstdio>
#include<iostream>
using namespace std;
int main(){
	int T;
	cin>>T;
	while(T-->0)
	{
		int n,x,y;
		cin>>n>>x>>y;
		cout<<min(max(x+y-n,0)+1,n)<<' '<<min(x+y-1,n)<<endl;
	}
	return 0;
}