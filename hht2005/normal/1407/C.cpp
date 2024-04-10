#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int p[N];
int main() {
	int n,now=1,x,y;
	scanf("%d",&n);
	for(int i=2;i<=n;i++) {
		cout<<"? "<<i<<' '<<now<<endl;
		cin>>x;
		cout<<"? "<<now<<' '<<i<<endl;
		cin>>y;
		if(x<y) {
			p[now]=y;
			now=i;
		} else p[i]=x;
	}
	p[now]=n;
	cout<<"!";
	for(int i=1;i<=n;i++)
		cout<<' '<<p[i];
	cout<<endl;
	return 0;
}