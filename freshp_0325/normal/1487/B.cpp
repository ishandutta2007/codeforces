#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,k;
LL fixNum(LL x){return !(x%n)?n:x%n;}
int main(){
	int T;
	cin>>T;
	while(T-->0)
	{
		cin>>n>>k;
		if(!(n&1))	cout<<fixNum(k)<<endl;
		else
		{
			LL rnd=(k-1)/(n/2);
			cout<<fixNum(k+rnd)<<endl;
		}
	}
	return 0;
}