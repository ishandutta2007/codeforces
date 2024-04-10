#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL upper[100005];
int main(){
	for(LL i=3;i<=100000;i+=2)	upper[i/2]=i*i;
	LL T;
	cin>>T;
	while(T-->0)
	{
		LL n;
		cin>>n;
		LL fuck=2*n+1;
		cout<<lower_bound(upper+1,upper+1+100000/2,fuck)-upper-1<<endl;
	}
	return 0;
}