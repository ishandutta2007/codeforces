#include<bits/stdc++.h>
using namespace std;
void Solve(){
	
	int x,y;
	scanf("%d %d",&x,&y);
	if((x+y)&1)
	{
		puts("-1");
		return ;
	}
	if(!x && !y)	puts("0");
	else if(x==y)	puts("1");
	else	puts("2");
}
int main(){
	int T;
	scanf("%d",&T);
	while(T-->0)	Solve();
	return 0;
}