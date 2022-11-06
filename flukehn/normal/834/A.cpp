#include<bits/stdc++.h>
using namespace std;
int t[1000];
int main(){
	char a,b;
	int n;
	scanf(" %c %c",&a,&b);
	scanf("%d",&n);
	n%=4;
	t['^']=0,t['>']=1,t['v']=2,t['<']=3;
	int c=(t[a]-t[b]+4)%4;
	if(n==0||n==2)puts("undefined");
	else puts(n!=c?"cw":"ccw");
}