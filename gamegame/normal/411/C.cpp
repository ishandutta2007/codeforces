#include<bits/stdc++.h>
using namespace std;
int a[5],b[5];
int main(){
	for(int i=1; i<=4 ;i++){
		cin >> a[i] >> b[i];
	}
	if(a[1]>b[3] && b[2]>a[4] && a[1]>b[4] && b[2]>a[3]) return cout << "Team 1\n",0;
	if(a[2]>b[3] && b[1]>a[4] && a[2]>b[4] && b[1]>a[3]) return cout << "Team 1\n",0;
	swap(a[1],a[3]);swap(b[1],b[3]);swap(a[2],a[4]);swap(b[2],b[4]);
	int x=a[1]>b[3] && b[2]>a[4];
	int y=a[1]>b[4] && b[2]>a[3];
	int w=a[2]>b[4] && b[1]>a[3];
	int z=a[2]>b[3] && b[1]>a[4];
	if((x||z) && (w||y)) return cout << "Team 2\n",0;
	cout << "Draw\n";
}