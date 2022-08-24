#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
struct stu{
	string name;
	int reg,sco;
};
bool cmp(stu i,stu j){
	return i.sco>j.sco;
}
int main(){
	int n,m;
	cin >> n >> m;
	vector<stu>a[m+1];
	stu temp;
	for(int i=1; i<=n ;i++){
		cin >> temp.name >> temp.reg >> temp.sco;
		a[temp.reg].push_back(temp);
	}
	for(int i=1; i<=m ;i++){
		sort(a[i].begin(),a[i].end(),cmp);
		if(a[i].size()==2){
			cout << a[i][0].name << ' ' << a[i][1].name << endl;
		}
		else if(a[i][1].sco==a[i][2].sco){
			cout << '?' << endl;
		}
		else{
			cout << a[i][0].name << ' ' << a[i][1].name << endl; 
		}
	}
}