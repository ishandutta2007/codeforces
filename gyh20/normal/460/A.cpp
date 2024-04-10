
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
long long n,m,b;

int main(){
	cin>>n>>m;
	while(n){
		b++;
		n--;
		if(b%m==0)n++;
	}
	cout<<b;
}