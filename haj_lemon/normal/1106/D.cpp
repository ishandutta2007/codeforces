#include<bits/stdc++.h>
#define ll long long
#define N 100010
using namespace std;
template <typename T> void read(T &x){
	x=0;char c=getchar();int fh=1;
	while (!isdigit(c)){if (c=='-')fh=-1;c=getchar();}
	while (isdigit(c))x=x*10+c-'0',c=getchar();
	x*=fh;
}
struct Info{int nu,ne;}a[N*2];
int b[N],num,m,n,x,y;
bool vi[N];
priority_queue<int,vector<int>,greater<int> > s;
void jb(int x,int y){a[++num].nu=y;a[num].ne=b[x];b[x]=num;}
int main(){
	read(n);
	read(m);
	for (int i=1;i<=n;i++) vi[i]=1;
	for (int i=1;i<=m;i++){read(x);read(y);jb(x,y);jb(y,x);}
	vi[1]=0;s.push(1);
	for (int i=1;i<=n;i++){
		int x=s.top();s.pop();
		for (int y=b[x];y;y=a[y].ne)if (vi[a[y].nu]){vi[a[y].nu]=0;s.push(a[y].nu);}
		printf("%d ",x);
	}
	puts("");
	return 0;
}