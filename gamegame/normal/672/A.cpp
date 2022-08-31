#include<iostream>
#include<vector>
using namespace std;
int main(){
	int cur,n,tot=0;
	vector<int>v(1),u;
	cin >> n;
	for(int i=1; tot<=1000 ;i++){
		cur=i;
		while(cur!=0){
			u.push_back(cur%10);
			cur/=10;
			tot++;
		}
		while(!u.empty()){
			v.push_back(u.back());
			u.pop_back();
		}
	}
	cout << v[n];
}