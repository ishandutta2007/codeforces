#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;

int a[999]; int len;
int n, r;

void ptpt(int x, int y) {
	//printf("x=%d y=%d\n", x,y);
	int sum=0;
	len=0;
	while(x>0 && y>0)
		if(x>y)
			sum+=(a[++len]=x/y), x%=y;
		else
			sum+=(a[++len]=y/x), y%=x;
			//printf("sum=%d\n",sum);
	if(x+y>1 || sum+1!=n) len=-1;
}

int main() {
	cin>>n>>r;
	int b=-1, bi;
	for(int i=0; i<=r; ++i) {
		ptpt(i, r-i); if(len>b) b=len, bi=i;
	}
	if(b<0) cout<<"IMPOSSIBLE"<<endl; else {
		ptpt(bi, r-bi); char c='T';
		if(len>0 && a[len]>1) a[len+1]=1, a[len]--, ++len;
		//printf("bi=%d b=%d len=%d\n", bi,b,len);
		cout<<(n-len-1)<<endl;
		for(int i=len; i>=1; --i) {
			for(int j=0; j<a[i]; ++j) cout<<c;
			c=(c=='T'?'B':'T');
		}
		cout<<c<<endl;
	}
	return 0;
}