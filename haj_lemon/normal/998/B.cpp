#include<bits/stdc++.h>
using namespace std;
int n,x,y,na,an[100010],a[100010],t,ansn;
int main(){
	cin>>n>>t;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=n-2;i++){
		if (a[i]%2==0) x++;else y++;
		if (x==y) an[++na]=abs(a[i+1]-a[i]);
	}
	sort(an+1,an+na+1);
	for (int i=1;i<=na;i++){
		if (t>=an[i]){t-=an[i];ansn++;}
	}
	cout<<ansn<<endl;
	return 0;
}