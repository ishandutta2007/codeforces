#include<bits/stdc++.h>
#define ll long long
#define N 1010
using namespace std;
template <typename T> void read(T &x){
	x=0;char c=getchar();int fh=1;
	while (!isdigit(c)){if (c=='-')fh=-1;c=getchar();}
	while (isdigit(c))x=x*10+c-'0',c=getchar();
	x*=fh;
}
struct Info{int x,y;}a[N],b[N];
int n;
bool c1(const Info &a,const Info &b){if (a.x!=b.x)return a.x<b.x;return a.y<b.y;}
bool c2(const Info &a,const Info &b){if (a.x!=b.x)return a.x>b.x;return a.y>b.y;}
int main(){
	read(n);
	for (int i=1;i<=n;i++){read(a[i].x);read(a[i].y);}
	for (int i=1;i<=n;i++){read(b[i].x);read(b[i].y);}
	sort(a+1,a+n+1,c1);sort(b+1,b+n+1,c2);
	cout<<a[1].x+b[1].x<<' '<<a[1].y+b[1].y<<endl;
	return 0;
}