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
char ch;
int n;
struct Info{ll l,ki;}a[N];
int main(){
	read(n);
	for (int i=1;i<=n;i++)read(a[i].l);
	for (int i=1;i<=n;i++){
		ch=getchar();while (ch!='G'&&ch!='W'&&ch!='L')ch=getchar();
		if (ch=='G')a[i].ki=1;if (ch=='W')a[i].ki=2;if (ch=='L')a[i].ki=3;
	}
	bool wa=0;ll sg=0,sn=0,ti=0;
	for (int i=1;i<=n;i++){
		if (a[i].ki==1){
			sg+=a[i].l*2;sn+=a[i].l;ti+=5*a[i].l;
		}
		if (a[i].ki==2){
			wa=1;sn+=a[i].l;ti+=3*a[i].l;
		}
		if (a[i].ki==3){
			ti+=a[i].l;
			if(sn>=a[i].l)sn-=a[i].l;
			else{
				ll x=a[i].l-sn;sn=0;
				if (wa)ti+=x*3;else ti+=x*5;
			}
		}
		sg=min(sg,sn);
	}
	cout<<ti-sn-sg<<endl;
	return 0;
}