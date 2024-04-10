#include <bits/stdc++.h>
using namespace std;
inline int rd() {
	int x=0,f=1;char ch=getchar();
	while (ch>'9'||ch<'0') {if(ch=='-')f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
	return x*f;
}

int n,x,y,o[100050],l,tmp;

int main() {
	n = rd(), x = rd(), y = rd();
	for (int i=1;i<=1024;i<<=1) {
		int cnt = 0;
		for (int j=0;j<n;j++) if (j&i) o[++cnt] = j+1;
		if (!cnt) continue;
		printf("? %d ",cnt);
		for (int j=1;j<=cnt;j++) printf("%d%c",o[j],j==cnt?'\n':' ');
		fflush(stdout);
		int sum = rd();
		if (sum != (cnt&1) * x) tmp ^= i, l = i;
	}
	
	int p1 = 0;
	for (int i=1;i<=1024;i<<=1) if (i!=l) {
		int cnt = 0;
		for (int j=0;j<n;j++) if (((j&l) == 0) && ((j&p1) == p1) && (j&i))
			o[++cnt] = j+1;
		if (!cnt) continue;
		printf("? %d ",cnt);
		for (int j=1;j<=cnt;j++) printf("%d%c",o[j],j==cnt?'\n':' ');
		fflush(stdout);
		int sum = rd();
		if (sum != (cnt&1) * x) p1 += i;
	}
	
	int p2 = p1 ^ tmp;
	printf("! %d %d\n",p1+1,p2+1);
	return 0;
}