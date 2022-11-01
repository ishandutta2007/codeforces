#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <ctime>
#include <map>
#include <queue>
#include <cstdlib>
#include <string>
#include <climits>
#include <set>
#include <vector>
using namespace std;
inline int read(){
	int k=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){k=k*10+ch-'0';ch=getchar();}
	return k*f;
}
int a[4],t1,t2;
int main()
{
	a[1]=read();a[2]=read();a[3]=read();t1=read();t2=read();
	a[2]/=5;a[3]/=5;sort(a+1,a+4);
	if(t1>t2)swap(t1,t2);
	if(t1<=a[1]){
		if(t2<=a[1]||t2>a[3])puts("YES");
		else puts("NO");
	}else if(t1>a[1]&&t1<=a[2]){
		if(t2>a[1]&&t2<=a[2])puts("YES");
		else puts("NO");
	}else if(t1>a[2]&&t1<=a[3]){
		if(t2>a[2]&&t2<=a[3])puts("YES");
		else puts("NO");
	}else if(t2>a[3])puts("YES");
	else puts("NO");
}