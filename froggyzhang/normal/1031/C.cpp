#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int A,B,t;
vector<int> vA,vB;
int main(){
	A=read(),B=read();
	int p=0;
	for(int i=1;;++i){
		if(p+i>A+B)break;
		p+=i;
		t=i;
	}
	for(int i=t;i>=1;--i){
		if(A>=i){
			vA.push_back(i);
			A-=i;
		}
		else{
			vB.push_back(i);
		}
	}
	printf("%d\n",(int)vA.size());
	for(auto x:vA){
		printf("%d ",x);
	}
	printf("\n%d\n",(int)vB.size());
	for(auto x:vB){
		printf("%d ",x);
	}
	printf("\n");
	return 0;
}