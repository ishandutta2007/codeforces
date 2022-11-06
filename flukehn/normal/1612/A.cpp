#include<bits/stdc++.h>
using namespace std;
void work(){
	int x,y;
	cin>>x>>y;
	if((x+y)%2){
		cout<<"-1 -1\n";
		return;
	}
	int u=x/2,v=y/2;
	if(x%2){
		if(u<x)++u;
		else ++v;
	}
	cout<<u<<" "<<v<<"\n";
	return;
}
int main(){
#ifdef flukehn
	freopen("a.in","r",stdin);
#endif
	ios::sync_with_stdio(0),cin.tie(0);
	int t;
	cin>>t;
	while(t--)work();
}