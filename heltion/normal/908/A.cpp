#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	char c[10]={'a','i','e','u','o','1','3','5','7','9'};
	cin>>s;
	int k=0;
	for(int i=0;i<s.length();++i)for(int j=0;j<10;++j)if(s[i]==c[j])k++;
	cout<<k;
}