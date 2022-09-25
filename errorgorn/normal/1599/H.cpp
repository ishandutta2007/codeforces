#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int) x.size())
#define show(x) cerr << #x << " is " << x << endl;
#define show2(x, y) cerr << #x << " is " << x << ", " << #y << " is " << y << endl;
#define show3(x,y,z) cerr << #x << " is " << x << " " << #y << " is " << y << " " << #z << " is " << z << endl;
typedef long long lint;
typedef pair<lint, lint> ii;


bool submit = true;

int LEFT = 5;
int TOP = 3;
int RIGHT = 12;
int BOTTOM = 12;

int query(int x, int y){
	
	cout << "? " << x << " " << y << endl;
	
	if(submit){
		int ans; cin >> ans;
		
		return ans;
	}
	else{	
		int ans = 0;
		
		if(x < LEFT) ans -= x-LEFT;
		if(RIGHT < x) ans -= RIGHT-x;
		
		if(y < TOP) ans -= y-TOP;
		if(BOTTOM < y) ans -= BOTTOM-y;
		
		cerr << ans << endl;
		return ans;
	}
}

int MAX = 1e9;

int main(){
	int TL = query(1,1);
	int BL = query(1,MAX);
	int TR = query(MAX,1);
	int BR = query(MAX,MAX);
	
	///horizontal middle = MAX/2 - (TR-TL-1)/2
	///vertical middle = MAX/2 - (BL-TL-1)/2
	
	int hmid = MAX/2 - (TR-TL-1)/2;
	int minval = query(hmid, 1);
	
	int low = 1, high = hmid;
	
	while(low != high-1){
		int mid = (low+high)/2;
		
		if(query(mid, 1) == minval) high = mid;
		else low = mid;
	}
	
	//show(high);
	
	int L = high;
	int T = TL + 2 - L;
	int R = MAX - (TR - T) - 1;
	int B = MAX - (BL - L) - 1;
	
	//show(L);
	//show(T);
	//show(R);
	//show(B);
	
	cout << "! " << L << " " << T << " " << R << " " << B << endl;
	exit(0);
}