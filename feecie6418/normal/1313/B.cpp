#include<bits/stdc++.h>
using namespace std;
int main() {
	int T;
	scanf("%d",&T);
	while(T--){
		int x,y,n;
		cin>>n>>x>>y;
		int tmp=max(x+y,n);
		int st=max(tmp-n+1,1),ed=min(tmp+1-st,n);
		cout<<n-max(ed-st,0)<<' '<<min(x+y-1,n)<<endl;
	}
}