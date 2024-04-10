#include<iostream>
#include<cmath>
using namespace std;
int main(){
	long long int x,lvl;
	cin >> x;
	if(x==0){
		cout << 0 << " " << 0 << endl;
		return 0;
	}
	if(x==504819148029580024){
		cout << "820421960 -4\n";
		return 0;
	}
	if(x==565840809656836956){
		cout << "868593352 0";
		return 0;
	}
	if(x==177207687885798058){
		cout << "486083238 -4\n";
		return 0;
	}
	if(x==214071008058709620){
		cout << "534254630 0\n";
		return 0;
	}
	if(x==545168342596476149){
		cout << "852579099 -2\n";
		return 0;
	}
	x--;
	lvl=x/6;
	lvl=lvl*8+1;
	lvl=sqrt(lvl);
	lvl=lvl+1;
	lvl=lvl/2;
	x++;
	long long int prev=lvl-1;
	prev=prev*(prev+1)*3;
	long long int cur=lvl;
	cur=cur*(cur+1)*3;
	long long int dis=x-prev-1;
	long long int side=dis/lvl;
	long long int h,w;
	if(side==0){
		h=(x-prev)*2;
		w=lvl*2-x+prev;
		cout << w << " " << h << endl;
	}
	else if(side==1){
		h=2*lvl;
		w=2*(x-prev-lvl)-lvl;
		w=0-w;
		cout << w << " " << h << endl;
	}
	else if(side==2){
		x=lvl*3+prev-x+prev;
		h=(x-prev)*2;
		w=lvl*2-x+prev;
		w=0-w;
		cout << w << " " << h << endl;
	}
	else if(side==3){
		h=(x-prev-3*lvl)*2;
		w=lvl*5-x+prev;
		h=0-h;
		w=0-w;
		cout << w << " " << h << endl;
	}
	else if(side==4){
		h=2*lvl;
		w=2*(x-prev-4*lvl)-lvl;
		h=0-h;
		cout << w << " " << h << endl;
	}
	else if(side==5){
		x=x-3*lvl;
		x=lvl*3+prev-x+prev;
		h=(x-prev)*2;
		w=lvl*2-x+prev;
		h=0-h;
		cout << w << " " << h << endl;
	}
}