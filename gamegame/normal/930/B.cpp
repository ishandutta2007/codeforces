#include<iostream>
#include<iomanip>
using namespace std;
int a[5000][26][26];
int open[26];
int main(){
	ios::sync_with_stdio(false);
	string s;
	cin >> s;
	int n=s.size();
	for(int i=0; i<n ;i++){
		for(int j=0; j<n ;j++){
			a[j][s[i]-'a'][s[(i+j)%n]-'a']++;
		}
	}
	int ans=0;
	for(int i=0; i<26 ;i++){
		for(int j=0; j<n ;j++){
			int cnt=0;
			for(int k=0; k<26 ;k++){
				if(a[j][i][k]==1) cnt++;
			}
			open[i]=max(open[i],cnt);
		}
		ans+=open[i];
	}
	cout << fixed << setprecision(15) << 1.0*ans/n << endl;
}