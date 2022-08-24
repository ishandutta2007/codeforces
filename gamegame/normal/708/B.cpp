#include<iostream>
#include<queue>
#include<cmath>
#include<algorithm>
using namespace std;
void imp(){
	cout << "Impossible\n";
	exit(0);
}
int main(){
	ios::sync_with_stdio(false);
	int a00,a01,a10,a11;
	cin >> a00 >> a01 >> a10 >> a11;
	int c0,c1;
	c0=sqrt(a00*2)+1;
	c1=sqrt(a11*2)+1;
	if(a00*2!=c0*(c0-1) || a11*2!=c1*(c1-1)) imp();
	if(c0==1 || c1==1){
		if(a01+a10==0){
			if(c0==1){
				for(int i=0; i<c1 ;i++) cout << 1;
			}
			else{
				for(int i=0; i<c0 ;i++) cout << 0;
			}
			return 0;
		}
	}
	if(a01+a10!=c0*c1) imp();
	int cur=c1;
	for(int i=0; i<c0 ;i++){
		if(a01==0){
			while(cur!=0){
				cout << 1;
				cur--;
			}
		}
		else if(a01<cur){
			while(cur!=a01){
				cout << 1;
				cur--;
			}
			a01=0;
		}
		else{
			a01-=cur;
		}
		cout << 0;
	}
	while(cur!=0){
		cout << 1;
		cur--;
	}
}