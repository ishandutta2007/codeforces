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
#include <complex>
using namespace std;
inline int read(){
	int k=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){k=k*10+ch-'0';ch=getchar();}
	return k*f;
}
inline void write(int x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);putchar(x%10+'0');
}
inline void writeln(int x){
	write(x);puts("");
}
const int N=50010;
int n,v[N],d[N],p[N];
bool la[N];
inline void work(int x){
	la[x]=1;
	for(int i=x+1;i<=n;i++)if(!la[i]){
		p[i]-=d[x];
		if(p[i]<0)work(i);
	}
}
int main()
{
	n=read();
	for(int i=1;i<=n;i++){
		v[i]=read();d[i]=read();p[i]=read();
	}
	int ans=0;
	for(int i=1;i<=n;i++)if(!la[i]){
		ans++;
		for(int j=i+1,k=v[i];k&&j<=n;k--,j++){
			while(la[j]&&j<=n)j++;if(j>n)break;
			if(p[j]>=0)p[j]-=k;
		}
		for(int j=i;j<=n;j++)if(!la[j]&&p[j]<0)work(j);
	}
	writeln(ans);
	for(int i=1;i<=n;i++)if(!la[i])write(i),putchar(' ');
	return 0;
}