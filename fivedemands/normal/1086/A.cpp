#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int x2[3],y2[3];
int x[3],y[3];
vector<int>ax,ay;
void add(int xx,int yy){
	ax.push_back(xx);
	ay.push_back(yy);
}
int main(){
	ios::sync_with_stdio(false);
	for(int i=0; i<3 ;i++){
		cin >> x[i] >> y[i];
		x2[i]=x[i],y2[i]=y[i];
	}
	sort(x2,x2+3);sort(y2,y2+3);
	bool ok=false;
	for(int i=0; i<3 ;i++){
		for(int j=x[i]; j<x2[1] ;j++) add(j,y[i]);
		for(int j=x[i]; j>x2[1] ;j--) add(j,y[i]);
		for(int j=y[i]; j<y2[1] ;j++) add(x2[1],j);
		for(int j=y[i]; j>y2[1] ;j--) add(x2[1],j);
		if(x2[1]==x[i] && y2[1]==y[i]) ok=true;
	}
	add(x2[1],y2[1]);
	cout << ax.size() << endl;
	for(int i=0; i<ax.size() ;i++) cout << ax[i] << ' ' << ay[i] << '\n';
}