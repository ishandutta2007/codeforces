#include<bits/stdc++.h>
using namespace std;
int Abs(int x){return x>0?x:-x;}
void Solve()
{
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	printf("%d\n",bool(Abs(a+c-2*b)%3));
}
int main(){
	int T;
	scanf("%d",&T);
	while(T-->0)	Solve();
	return 0;
}