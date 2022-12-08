#include<bits/stdc++.h>
using namespace std;
const int N=10010;
int f[N],p[N];
int main() {
	int T,n,x;
	scanf("%d",&T);
	while(T--) {
		int pos=0,A=0,B=0;
		scanf("%d",&n);
		for(int i=1;i+1<=n;i+=2) {
			cout<<"? 2 "<<i<<' '<<i+1<<" 1"<<endl;
			cin>>x;
			if(x==1) {
				pos=i;
				break;
			}
			if(x==2) {
				if(!A)A=i+1;
				else {
					B=i+1;
					break;
				}
			}
		}
		if(n&1) {
			cout<<"? 2 "<<n<<" 1 1"<<endl;
			cin>>x;
			if(x==1)pos=n;
		}
		if(!pos) {
			if(!B)pos=A;
			else {
				cout<<"? 2 "<<A<<' '<<B<<' '<<1<<endl;
				cin>>x;
				if(x==1)pos=A;
				else pos=B;
			}
		}
		p[pos]=1;
		for(int i=1;i<=n;i++) {
			if(i==pos)continue;
			cout<<"? 1 "<<pos<<' '<<i<<' '<<n-1<<endl;
			cin>>x;
			p[i]=x; 
		}
		cout<<"!";
		for(int i=1;i<=n;i++)
			cout<<' '<<p[i];
		cout<<endl;
	}
	return 0;
}