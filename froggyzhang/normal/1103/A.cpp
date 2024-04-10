#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
const int d[4][2]={{1,1},{2,1},{3,1},{4,1}};
const int c[2][2]={{1,4},{3,4}};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>s;
	int i=0,j=0;
	for(auto x:s){
		if(x=='1'){
			cout<<d[i][0]<<' '<<d[i][1]<<'\n';
			i=(i+1)%4;
		}
		else{
			cout<<c[j][0]<<' '<<c[j][1]<<'\n';
			j=(j+1)%2;
		}
	}
	return 0;
}