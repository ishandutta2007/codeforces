#include<bits/stdc++.h>
#define ll long long
#define N 300010
using namespace std;
template <typename T> void read(T &x){
	x=0;char ch=getchar();int fh=1;
	while (ch<'0'||ch>'9'){if (ch=='-')fh=-1;ch=getchar();}
	while (ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	x*=fh;
}
int m,n,a[N];
bool pa(int x){
	int la=0;
	for (int i=1;i<=n;i++){
		if (a[i]+x<m){
			if (la>a[i]+x) return 0;
			else la=max(la,a[i]);
		}else{
			int p=(a[i]+x)%m;
			if (la>p)la=max(la,a[i]);
		}
	}
	return 1;
}
int main(){
	read(n);read(m);
	for (int i=1;i<=n;i++)read(a[i]);
	int l=0,r=m,mid;
	while (l<r){
		mid=(l+r)/2;
		if (pa(mid))r=mid;else l=mid+1;
	}
	cout<<l<<endl;
	return 0;
}