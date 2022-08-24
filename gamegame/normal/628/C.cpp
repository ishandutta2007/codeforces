#include<iostream>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	int n,k;
	cin >> n >> k;
	string m;
	cin >> m;
	int maxi=0;
	for(int i=0; i<m.size() ;i++){
		maxi+=max(m[i]-97,122-m[i]);
	}
	if(maxi<k){
		cout << "-1\n";
		return 0;
	}
	int used=0;
	for(int i=0; i<m.size() ;i++){
		if(k-used>=max(m[i]-97,122-m[i])){
			if(m[i]-97>122-m[i]){
				cout << 'a';
			}
			else{
				cout << 'z';
			}
			used+=max(m[i]-97,122-m[i]);
		}
		else if(m[i]-97>122-m[i]){
			cout << (char)(m[i]+used-k);
			used=k;
		}
		else{
			cout << (char)(m[i]-used+k);
			used=k;
		}
	}
}