#include<iostream>
using namespace std;
int n;
int ax,ay,bx,by,cx,cy;
int f(int x,int y){
	return (x<0)*2+(y<0);
}
int main(){
	cin >> n;
	cin >> bx >> by >> ax >> ay >> cx >> cy;
	if(f(ax-bx,ay-by)==f(cx-bx,cy-by)) cout << "YES\n";
	else cout << "NO\n";
}