#include <iostream>
#include <cstdio>
#define N 400050
using namespace std;

char s[N];
int n,ans;

bool check(int &xx,int &yy,int &x,int &y) {
	bool r = true;
	if (x && xx && xx != x) r = false;
	if (y && yy && yy != y) r = false;
	if (x) xx = x; 
	if (y) yy = y;
	return r;
}

int main()
{
	int x = 0 , y = 0 , xx = 0 , yy = 0;
	scanf("%d",&n); scanf("%s",s+1);
	for (int i=1;i<=n;i++) {
		x = y = 0;
		if (s[i] == 'L') x = -1;
		if (s[i] == 'R') x =  1;
		if (s[i] == 'U') y = 1;
		if (s[i] == 'D') y = -1;
		if (!check(xx,yy,x,y)) {
			ans++;
			xx = x; yy = y;
		} 
	}
	printf("%d\n",1+ans);
	return 0;
}