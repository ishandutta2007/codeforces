#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int xa,ya,xb,yb,xf,yf;
		cin >> xa >> ya >> xb >> yb >> xf >> yf;
		int D=max(xb,xa)-min(xb,xa)+max(yb,ya)-min(yb,ya);
		if(xa==xb&&xb==xf&&yf<=max(ya,yb)&&yf>=min(ya,yb))
			cout << D+2 << "\n";
		else if(ya==yb&&yb==yf&&xf<=max(xa,xb)&&xf>=min(xa,xb))
			cout << D+2 << "\n";
		else cout << D<< "\n"; 
	}
	return 0;
}
//