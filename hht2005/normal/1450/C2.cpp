#include<bits/stdc++.h>
using namespace std;
const int N=310;
char s[N][N];
int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		int n,Min=1e9,A=-1,B=-1;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%s",s[i]+1);
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++) {
				if(i==j)continue;
				int cnt=0;
				for(int a=1;a<=n;a++)
					for(int b=1;b<=n;b++) {
						if((a+b)%3==i&&s[a][b]=='O')cnt++;
						if((a+b)%3==j&&s[a][b]=='X')cnt++;
					}
				if(cnt<Min) {
					Min=cnt;
					A=i,B=j;
				}
			}
		for(int a=1;a<=n;a++)
			for(int b=1;b<=n;b++) {
				if((a+b)%3==A&&s[a][b]=='O')s[a][b]='X';
				if((a+b)%3==B&&s[a][b]=='X')s[a][b]='O';
			}
		for(int i=1;i<=n;i++)
			printf("%s\n",s[i]+1);
	}
	return 0;
}