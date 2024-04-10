#include<iostream>
#include<cstdio>
using namespace std;
int T,N;
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N;
		int K=0;while(K*2+1<N)K=K*2+1;cout<<K<<endl; 
	}
	return 0;
}