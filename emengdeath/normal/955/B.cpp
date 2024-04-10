#include<bits/stdc++.h>
using namespace std;
string s;
int sum[26];
int main(){
	ios::sync_with_stdio(false);
	cin>>s;
	for (int i=0;i<s.size();i++)
		sum[s[i]-'a']++;
	int d[27];
	d[0]=0;
	for (int i=0;i<26;i++)	
		if (sum[i])d[++d[0]]=sum[i];
	if (d[0]>4||d[0]<=1){
		cout<<"No";
		return 0;
	}
	if (d[0]==4){
		cout<<"Yes";
		return 0;
	}
	if (d[0]==3){
		if (d[1]>1||d[2]>1||d[3]>1)cout<<"Yes";
		else
			cout<<"No";
		return 0;
	}
	if (d[1]>1&&d[2]>1)cout<<"Yes";
	else
		cout<<"No";
	return 0;
}