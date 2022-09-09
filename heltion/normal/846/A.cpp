#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
	int N;
	cin>>N;
	int* s=new int[N+1];
	s[0]=0;
	for(int i=1;i<=N;i++){
		int si;
		cin>>si;
		s[i]=s[i-1]+si;
	}
	int m=max(s[N],N-s[N]);
	
	for(int i=1;i<N;i++)
		m=max(m,i-s[i]+s[N]-s[i]);
	cout<<m;
}