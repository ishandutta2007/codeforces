#include<iostream>
#include<algorithm>
using namespace std;
int n;
string s;
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> s;
	sort(s.begin(),s.end());
	cout << s << endl;
}