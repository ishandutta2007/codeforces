#include<bits/stdc++.h>
using namespace std;
long long n,k,l,r,mid,xia,sh,no;
bool que(long long l,long long r){
	cout<<l<<' '<<r<<endl;
	fflush(stdout);
	string s;cin>>s;
	if (l==r&&s=="Yes")exit(0);
	if (s[0]=='Y')return true;return false;
}
int main(){
	srand('z'+'h'+'r');
	cin>>n>>k;
	l=1,r=n,mid;
	while (1){
		while (r-l+1>80){
			mid=(l+r)/2;
			if (que(l,mid)){
				l=max(1ll,l-k);r=min(mid+k,n);
			}else{
				l=max(1ll,mid+1-k);r=min(n,r+k);
			}
		}
		xia=l;sh=r;no=xia+rand()%(sh-xia+1);
		que(no,no);
		l=max(1ll,l-k);r=min(n,r+k);
	}
	return 0;
}
/*
1000000000000000000 10
*/