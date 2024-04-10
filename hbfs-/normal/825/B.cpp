#include <bits/stdc++.h>
using namespace std;
inline int rd() {
	int x=0,f=1;char ch=getchar();
	while (ch>'9'||ch<'0') {if(ch=='-')f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
	return x*f;
}

const int fx[] = { 0, 0, 1,-1, 1,-1, 1,-1};
const int fy[] = { 1,-1, 0, 0, 1,-1,-1, 1};
char s[105];
int mp[105][105],flag;

bool check(int x,int y) {
	int cx,cy,t1;

	for (int i=0;i<=6;i+=2) {

		cx=x,cy=y,t1=1;
		while (mp[cx+fx[i]][cy+fy[i]] == 1)
			cx += fx[i], cy += fy[i], t1++;
		cx=x,cy=y;
		while (mp[cx+fx[i+1]][cy+fy[i+1]] == 1)
			cx += fx[i+1], cy += fy[i+1], t1++;

		if (t1>=5) return 1;

	}
	
	return 0;

}

int main() {
	for (int i=1;i<=10;i++) {
		scanf("%s",s+1);
		for (int j=1;j<=10;j++) {
			if (s[j]=='X') mp[i][j] = 1;
			if (s[j]=='O') mp[i][j] = -1;
		}
	}
	
	for (int i=1;i<=10;i++)
		for (int j=1;j<=10;j++)
			if (!mp[i][j] && check(i,j))
				{flag = 1; break;}
	puts(flag?"YES":"NO");
	return 0;
}