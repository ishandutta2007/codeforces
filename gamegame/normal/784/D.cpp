#include<iostream>
using namespace std;
int p[10]={8,-1,-1,3,6,9,4,7,0,5};
int main(){
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    for(int i=0; i<s.size() ;i++){
    	if(p[s[i]-48]!=s[s.size()-i-1]-48){
    		cout << "No\n";
    		return 0;
		}
	}
	cout << "Yes\n";
}