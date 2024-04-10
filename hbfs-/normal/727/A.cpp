#include <iostream>
#include <cstdio>

using namespace std;

int o[1050],a,b,top;

bool DFS(int x,int dep) {
	o[dep] = x;
	if (x == a) {
		top = dep;
		return true;
	}
	if (x < a) return false;
	if (x % 10 == 1) {
		if (DFS(x/10,dep+1) ) return true;
	}
	if (x % 2 == 0) {
		if (DFS(x/2,dep+1)) return true;
	}
	return false;
}

int main()
{
	scanf("%d%d",&a,&b);
	bool flag = DFS(b,1);
	if (flag) {
		printf("YES\n"); printf("%d\n",top);
		for (int i=top;i>=1;i--) printf("%d%c",o[i],i==1?'\n':' '); 
	} else puts("NO");
	return 0;
}