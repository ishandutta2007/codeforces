#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
int main(){
	int x,y,z;
	cin>>x>>y>>z;
	x=min(x,min(y-1,z-2));
	cout<<3*x+3; 
}