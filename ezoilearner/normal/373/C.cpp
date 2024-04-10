#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int n;
#define maxn 500010
int a[maxn];
void rd(int &x){x=0;char ch=getchar();while(ch<'0'||ch>'9')ch=getchar();while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}}
int main(){
    rd(n);
	for(int i=1;i<=n;++i)rd(a[i]);
	sort(a+1,a+n+1);
	int ans=n;
	for(int i=n/2;i;--i)
	if(a[ans]>=a[i]*2)ans--;
	printf("%d\n",ans);
	return 0;
}