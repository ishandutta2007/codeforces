#include<bits/stdc++.h>
using namespace std;
int bw(){
	char s[111];
	cin>>s;
	return s[0]=='b';
}
int main(){
	int l=1,r=1e9,n,m,c;
	cin>>n;
	cout<<"0 1"<<endl;
	c=bw();
	--n;
	while(n){
		m=l+r>>1;
		cout<<m<<" 1"<<endl;
		if(bw()==c)
			l=m+1;
		else
			r=m-1;
		--n;
	}
	//++l;
	//if(l<r)++l;
	//l=l+r>>1;
	cout<<l<<" 0 "<<r<<" 2"<<endl;
}