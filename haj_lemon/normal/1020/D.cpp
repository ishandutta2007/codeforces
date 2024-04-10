#include<bits/stdc++.h>
using namespace std;
int n,x,y;
int que(int x){
	cout<<"? "<<x<<endl;
	fflush(stdout);
	int y;
	cin>>y;
	return y;
}
int main(){
	cin>>n;
	if (n%4!=0){cout<<"! -1"<<endl;return 0;}
	x=que(1);y=que(n/2+1);
	if (x-y==0){cout<<"! 1"<<endl;return 0;}
	int l=1,r=n/2+1,mid;
	if (x<y){
		while (l+1<r){
			mid=(l+r)/2;
			x=que(mid);y=que(mid+n/2);
			if (x==y){cout<<"! "<<mid<<endl;return 0;}
			if (x>y)r=mid;else l=mid;
		}
		x=que(l),y=que(l+n/2);
		if (x==y) cout<<"! "<<l<<endl;
		else cout<<"! "<<r<<endl;
	}else{
		while (l+1<r){
			mid=(l+r)/2;
			x=que(mid);y=que(mid+n/2);
			if (x==y){cout<<"! "<<mid<<endl;return 0;}
			if (x>y)l=mid;else r=mid;
		}
		x=que(l),y=que(l+n/2);
		if (x==y) cout<<"! "<<l<<endl;
		else cout<<"! "<<r<<endl;		
	}
	return 0;
}