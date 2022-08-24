#include<iostream>
using namespace std;
int sumx,sumy;
int cnt=0;
int main(){
	int n,m;
	cin >> n >> m;
	for(int i=1; i<=n ;i++){
		for(int j=1; j<=m ;j++){
			char c;
			cin >> c;
			if(c=='B'){
				sumx+=i;
				sumy+=j;
				cnt++;
			}
		}
	}
	cout << sumx/cnt << ' ' << sumy/cnt << endl;
}