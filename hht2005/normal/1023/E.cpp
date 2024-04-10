#include<bits/stdc++.h>
using namespace std;
const int N=1010;
char S[N],ans[5];
int main() {
	int n,x=1,y=1;
	scanf("%d",&n);
	for(int i=1;i<n;i++) {
		cout<<"? "<<x<<' '<<y+1<<' '<<n<<' '<<n<<endl;
		cin>>ans;
		if(ans[0]=='Y') {
			S[i]='R';
			y++;
		} else {
			S[i]='D';
			x++;
		}
	}
	x=y=n;
	for(int i=1;i<n;i++) {
		cout<<"? "<<1<<' '<<1<<' '<<x-1<<' '<<y<<endl;
		cin>>ans;
		if(ans[0]=='Y') {
			S[2*n-i-1]='D';
			x--;
		} else {
			S[2*n-i-1]='R';
			y--;
		}
	}
	cout<<"! "<<S+1<<endl;
	return 0;
}