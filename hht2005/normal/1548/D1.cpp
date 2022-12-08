#include<bits/stdc++.h>
using namespace std;
int t[4][4];
int main() {
	int n,x,y;
	long long ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d%d",&x,&y);
		t[x%4][y%4]++;
	}
	for(int x1=0;x1<4;x1++)
		for(int y1=0;y1<4;y1++)
			for(int x2=0;x2<4;x2++)
				for(int y2=0;y2<4;y2++)
					for(int x3=0;x3<4;x3++)
						for(int y3=0;y3<4;y3++)
							if((__gcd(abs(x1-x2),abs(y1-y2))+__gcd(abs(x2-x3),abs(y2-y3))+__gcd(abs(x1-x3),abs(y1-y3)))%4==0) {
								long long T=t[x1][y1]--;
								T*=t[x2][y2]--;
								ans+=T*t[x3][y3];
								t[x2][y2]++;
								t[x1][y1]++;
							}
	printf("%lld\n",ans/6);
	return 0;
}