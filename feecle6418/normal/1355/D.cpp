#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
int a,b;
int main(){
	cin>>a>>b;
	if(b<a*2)return puts("NO"),0;
	puts("YES");
	for(int i=1;i<a;i++)cout<<"1 ";
	cout<<b-a+1<<endl;
	cout<<b-a<<endl;
}