#include<cstdio>
#include<algorithm>
#include<queue>
#include<iostream>
using namespace std;
int main(){
	long long T;
	cin>>T;
	while(T-->0)
	{
		long long n,lasta=0,lastb=0;
		bool flag=false;
		cin>>n;
		for(int i=1;i<=n;++i)
		{
			int a,b;
			cin>>a>>b;
			if(a<b || b-lastb>a-lasta || b<lastb || a<lasta)	flag=true;
			lasta=a,lastb=b; 
		}
		if(flag)	puts("NO");
		else	puts("YES");
	}
	return 0;
}