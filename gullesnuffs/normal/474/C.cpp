#include <bits/stdc++.h>

using namespace std;

int n;
int x[4], y[4], a[4], b[4];

bool isSquare(){
	int p[4];
	iota(p, p+4, 0);
	do{
		bool ok=1;
		int len=-1;
		for(int i=0; i < 4; ++i){
			int c=p[i], d=p[(i+1)%4], e=p[(i+2)%4];
			int x1=x[c]-x[d], y1=y[c]-y[d], x2=x[e]-x[d], y2=y[e]-y[d];
			int dot=x1*x2+y1*y2;
			if(x1 == x2 && y1 == y2)
				ok=0;
			if(dot)
				ok=0;
			int len2=x1*x1+y1*y1;
			if(len != -1 && len2 != len)
				ok=0;
			len=len2;
		}
		if(len == 0)
			ok=0;
		if(ok)
			return 1;
	}while(next_permutation(p, p+4));
	return 0;
}

int rec(int ind, int moveN){
	if(ind == 4){
		if(isSquare())
			return moveN;
		else
			return 100;
	}
	int ans=100;
	for(int i=0; i < 4; ++i){
		ans=min(ans, rec(ind+1, moveN));
		int dx=x[ind]-a[ind], dy=y[ind]-b[ind];
		x[ind]=a[ind]-dy, y[ind]=b[ind]+dx;
		++moveN;
	}
	return ans;
}

int main(){
	scanf("%d", &n);
	for(int i=0; i < n; ++i){
		for(int j=0; j < 4; ++j)
			scanf("%d%d%d%d", x+j, y+j, a+j, b+j);
		int res = rec(0, 0);
		if(res == 100)
			puts("-1");
		else
			printf("%d\n", res);
	}
}