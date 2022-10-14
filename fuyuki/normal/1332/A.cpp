#include<bits/stdc++.h>
using namespace std;
#define I inline int
#define V inline void
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
const int N=2e5+1;
int T;
int a,b,c,d;
int x,y,lx,rx,ly,ry;
V input(){
	cin>>a>>b>>c>>d;
	cin>>x>>y>>lx>>ly>>rx>>ry;
}
V init(){
	if(lx==rx&&(a||b))return void(cout<<"NO\n");
	if(ly==ry&&(c||d))return void(cout<<"NO\n");
	if(b-a+x>rx)return void(cout<<"NO\n");
	if(x+b-a<lx)return void(cout<<"NO\n");
	if(d-c+y>ry)return void(cout<<"NO\n");
	if(y+d-c<ly)return void(cout<<"NO\n");
	cout<<"YES\n";
}
V work(){
	
}
int main(){
	for(cin>>T;T--;){
		input();
		init();
		work();
	}
	return 0;
}