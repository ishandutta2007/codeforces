#include <bits/stdc++.h>

using namespace std;

int sgn(int x){
	return x>0?1:-1;
}

int main(){
	int x,y;
	scanf("%d%d", &x, &y);
	int ax=abs(x),ay=abs(y);
	int sx=sgn(x),sy=sgn(y);
	int ans;
	if(ax >= ay){
		if(x > 0)
			ans=4*ax-3;
		else
			ans=4*ax-1;
		if(ax == ay){
			if(sx != sy){
				--ans;
				if(x > 0)
					ans = 4*ax;
			}
		}
	}
	else{
		if(y > 0)
			ans=4*ay-2;
		else
			ans=4*ay;
	}
	if(x > 0 && y < 0 && ax == ay+1)
		ans=ax*4-4;
	if(x == 0 && y == 0)
		ans=0;
	if(x == 1 && y == 0)
		ans=0;
	printf("%d\n", ans);
}