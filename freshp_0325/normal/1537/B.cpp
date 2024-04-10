#include<bits/stdc++.h>
using namespace std;
int Abs(int x){return x<0?-x:x;}
int getDis(int a,int b,int c,int d){return Abs(a-c)+Abs(b-d);}
int main(){
	int T;
	scanf("%d",&T);
	while(T-->0)
	{
		int n,m,i,j;
		scanf("%d %d %d %d",&n,&m,&i,&j);
		printf("%d %d %d %d\n",1,1,n,m);
	}
	return 0;
}