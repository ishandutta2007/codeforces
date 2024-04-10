#include<bits/stdc++.h>
using namespace std;
long long a,b,c,aa,bb,cc,has;
int main()
{
	cin>>a>>b>>c;
	aa=a;
	bb=b/2;
	cc=c/4;
	has=min(a,bb);
	has=min(has,cc);
	cout<<has*7<<endl;
}