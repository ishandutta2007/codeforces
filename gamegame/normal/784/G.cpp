#include<iostream>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;
int n,p,t;
int cnt[101];
int main(){
	ios::sync_with_stdio(false);
	string s;
	cin >> s;
	s=s+'+';
	int ans=0;
	int cur=0;
	int sign=1;
	for(int i=0; i<s.size() ;i++){
		if(s[i]>=48 && s[i]<=57) cur=cur*10+s[i]-48;
		else{
			if(sign==1) ans+=cur;
			else ans-=cur;
			if(s[i]=='+') sign=1;
			else sign=-1;
			cur=0;
		}
	}
	for(int i=100; i>=1; i/=10){
		if(ans/i!=0){
			cur=ans%(i*10)/i;
			for(int j=0; j<cur+48 ;j++){
				cout << '+';
			}
			cout << ".>\n";
		}
	}
	if(ans==0){
		for(int j=0; j<48 ;j++){
			cout << '+';
		}
		cout << ".\n";
	}
}