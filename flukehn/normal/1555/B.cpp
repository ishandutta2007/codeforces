#include<bits/stdc++.h>
using namespace std;
const int oo=~0u>>1;
#define y1 y1_r
int work(){
	int W,H,x1,y1,u,v,w,h;
	cin>>W>>H>>x1>>y1>>u>>v>>w>>h;
	int x2=max(x1,W-u),y2=max(y1,H-v);
	int x3=min(x1,W-u),y3=min(y1,H-v);
	if(x1+W-u<w&&y1+H-v<h){
		return -1;
	}
	if(x2>=w||y2>=h){
		return 0;
	}
	else{
		return min(w<=x2+x3?w-x2:oo,h<=y2+y3?h-y2:oo);
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		cout<<work()<<"\n";	
	}
}