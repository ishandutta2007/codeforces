#include<bits/stdc++.h>
using namespace std;
int f[6][3]={
	{0,1,2},
	{1,0,2},
	{1,2,0},
	{2,1,0},
	{2,0,1},
	{0,2,1}
};
int main(){
	int x,n;
	scanf("%d%d",&n,&x);
	n%=6;
	return printf("%d\n",f[n][x]),0;
}