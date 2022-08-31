#include<iostream>
using namespace std;
int n;
int d[301];
int a[1002][1002];
int sz;
int last;
bool gd[1002];
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<=n ;i++){
		cin >> d[i];
	}
	for(int i=n; i>n/2 ;i--){
		int k=n+1-i;
		//cout << "Add " << d[i]+1 << endl;
		for(int j=d[i]+1-d[k]+1; j<=d[i]+1 ;j++) gd[j]=true;
		for(int j=n+1-i+1; j<i ;j++) d[j]-=d[n+1-i];
	}
	int cnt=0;
	for(int i=1; i<=d[n]+1 ;i++){
		for(int j=i+1; j<=d[n]+1 ;j++){
			if(gd[j]) cnt++;
			a[i][j]=gd[j];
		}
	}
	cout << cnt << endl;
	for(int i=1; i<=d[n]+1 ;i++){
		for(int j=i+1; j<=d[n]+1 ;j++){
			if(gd[j]) cout << i << ' ' << j << '\n';
		}
	}
}