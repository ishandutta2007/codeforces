#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
int main(){
	int T;
	cin>>T;
	while(T-->0)
	{
		int n,a,b,c,d;
		cin>>n>>a>>b>>c>>d;
		int le=(a-b)*n,re=(a+b)*n;
		if(le>c+d || re<c-d)	puts("No");
		else	puts("Yes");
	}
	return 0;
}