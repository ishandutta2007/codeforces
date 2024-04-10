#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
int a[10][2]={{7,5},{4,4},{4,5},{4,6},{5,4},{5,5},{5,6},{6,4},{6,5},{6,6}};
bool ok[11][11];
int main(){
	ios::sync_with_stdio(false);
	int n,m,k;
	cin >> n;
	string s;
	cin >> s;
	for(int i=0; i<=10 ;i++){
		ok[a[i][0]][a[i][1]]=true;
	}
	for(int i=0; i<s.size() ;i++) s[i]-=48;
	bool ok1=true;
	for(int i=-3; i<=3 ;i++){
		for(int j=-3; j<=3 ;j++){
			if(i==0 & j==0) continue;
			bool ok2=true;
			for(int k=0; k<s.size() ;k++){
				if(!ok[a[s[k]][0]+i][a[s[k]][1]+j]) ok2=false;
			}
			if(ok2) ok1=false;
		}
	}
	if(ok1) cout << "YES\n";
	else cout << "NO\n";
}