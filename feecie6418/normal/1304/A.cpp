#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int main() {
	int T;
	cin>>T;
	while(T--){
		int x,y,a,b;
		cin>>x>>y>>a>>b;
		if((y-x)%(a+b))puts("-1");
		else printf("%d\n",(y-x)/(a+b));
	}
}