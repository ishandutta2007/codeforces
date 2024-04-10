#include <iostream>
#include <cstdio>
#include <cstring>

#define N 1050

using namespace std;
char s[N];
int a[N],p[N],n,tot;

int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

inline bool check(char x) {
	switch(x) {
		case 'a' :{return true; break; }
		case 'e' :{return true; break; }
		case 'i' :{return true; break; }
		case 'o' :{return true; break; }
		case 'u' :{return true; break; }
		case 'y' :{return true; break; }
	}
	return false;
}

int main()
{
	bool flag = true;
	n = read();
	for (int i=1;i<=n;i++) p[i] = read();
	for (int i=1;i<=n;i++) {
		tot = 0; char ch;
		while ((ch = getchar()) != '\n') {
			if (check(ch)) tot++;
		}

		if (tot != p[i]) {
			flag = false;
			break;
		}
	}
	if (flag)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}