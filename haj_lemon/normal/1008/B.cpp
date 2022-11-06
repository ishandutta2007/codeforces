#include<bits/stdc++.h>
using namespace std;
int n,last,x,y;
bool c=true;
int main(){
	scanf("%d",&n);
	last=1000000000;
	for (int i=1;i<=n;i++){
		scanf("%d %d",&x,&y);
		if (x>y) swap(x,y);
		if (y<=last) last=y;
		else{
			if (x<=last) last=x;
			else c=false;
		}
	}
	if (c) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}