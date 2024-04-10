#include<string>
#include<iostream>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
string x;
int f(int x){return (x>>1)+(x&1);}
int main(){
	int tag=1;cin>>x;
	FOR(i,1,x.size()-1)if(x[i]=='1')tag=0;
	cout<<f(x.size()-tag);
	return 0;
}