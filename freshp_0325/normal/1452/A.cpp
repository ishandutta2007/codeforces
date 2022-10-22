#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;
	cin>>T;
	while(T-->0)
	{
		int x,y;
		cin>>x>>y;
		cout<<max(x,y)*2-1+int(x==y)<<endl;
	}
	return 0;
}