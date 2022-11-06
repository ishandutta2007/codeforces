#include<bits/stdc++.h>
using namespace std;
string st;
bool c=true;
int main(){
	cin>>st;
	for (int i=0;i<st.length();i++){
		if (st[i]!='a'&&st[i]!='i'&&st[i]!='e'&&st[i]!='o'&&st[i]!='u'&&st[i]!='n'){
			if (st[i+1]=='a'||st[i+1]=='i'||st[i+1]=='e'||st[i+1]=='u'||st[i+1]=='o'){;}else c=false;
		}
	}
	if (c) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}