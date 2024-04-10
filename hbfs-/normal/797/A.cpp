#include <bits/stdc++.h>
#define N 1000500
using namespace std;
inline int rd() {
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int o[N],n,k,cnt;

int main() {
	int n = rd(), k = rd(), cnt = 0;
	for (int i=2;i<=n;i++)
		while (n % i == 0) { n /= i, o[++cnt] = i; }
	if (n != 1) o[++cnt] = n;
	
	if (cnt < k) return puts("-1"), 0;
	for (int i=1;i<k;i++) printf("%d ",o[i]);
	
	int ans = 1;
	for (int i=k;i<=cnt;i++) ans *= o[i];
	printf("%d\n",ans);
	
	return 0;
}