#include <bits/stdc++.h>
using namespace std;
#define rep(a,b,c) for(int a=b;a<c;++a)
#define debug(x) cerr<<(#x)<<": "<<x<<endl;
const int sz = 2e6;

long long n;
int main()
{
	scanf("%d",&n);
    if(n==1)
		cout<<1<<endl;
	else if(n==2)
		cout<<2<<endl;
	else if(n&1)
		cout << n*(n-1)*(n-2)<<endl;
	else if(n%3==0)
		cout << (n-1)*(n-2)*(n-3)<<endl;
	else
		cout << n*(n-1)*(n-3)<<endl;
}