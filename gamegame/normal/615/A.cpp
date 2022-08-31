#include<iostream>
using namespace std;
int main(){
	int x,y,p,q;
	cin >> x >> y;
	int a[y+1];
	for(int i=1; i<=y ;i++){
		a[i]=0;
	}
	for(int i=0; i<x ;i++){
		cin >> p;
		for(int j=0; j<p ;j++){
			cin >> q;
			a[q]=1;
		}
	}
	for(int i=1; i<=y ;i++){
		if(a[i]==0){
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
}