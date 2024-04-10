#include<iostream>
#include<string>
using namespace std;
int main(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	for(int i=1;i<n;i++)
		if(s[i-1]==s[i]&&s[i]!='?'){
			cout<<"NO";
			return 0;
		}
	for(int i=0;i<n;i++)
		if(s[i]=='?')
			if(i==0||i==n-1||s[i-1]=='?'||s[i+1]=='?'||s[i-1]==s[i+1]){
				cout<<"YES";
				return 0;
			}
	cout<<"NO";
	return 0;
}