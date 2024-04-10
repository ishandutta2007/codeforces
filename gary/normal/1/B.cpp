#include<bits/stdc++.h>
using namespace std;
char zimu[26]={'Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y'},rcans[4000];
bool check(string val){
	int flag=0;
	for(int i=1;i<val.length();i++){
		if(!(val[i-1]>='0'&&val[i-1]<='9')&&(val[i]>='0'&&val[i]<='9')) flag++;
	}
	if(flag==1) return true;
	else return false;
}
void ex(string val){

	long i=0;
	long c=0,r=0;
	while(!(val[i]<='9'&&val[i]>='0')){// 
		c*=26;
		c+=(val[i]-'A'+1);i++;
	}
	for(long long j=i;j<val.length();j++){
		r*=10;
		r+=val[j]-'0';
	}
	cout<<"R"<<r<<"C"<<c<<endl;
} 
void rc(string val){
	long long rclen=1;
	long long i=1;
	long long r=0,c=0;
	while(val[i]>='0'&&val[i]<='9'){
		r*=10;
		r+=val[i]-'0';
		i++;
	}
	for(long long j=i+1;j<val.length();j++){
		c*=10;
		c+=val[j]-'0';
	}
	while(1){
		rcans[rclen]=zimu[c%26];
		rclen++;
		if(c%26==0) c-=1;
		c/=26;
		if(c==0) break;
	}
	for(long long j=rclen-1;j>=1;j--) cout<<rcans[j];
	cout<<r<<endl;
}
int main(){
//	freopen("spreadsheets.in","r",stdin);
//	freopen("spreadsheets.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		string str;
		cin>>str;
		if(check(str)) ex(str);//ex 
		else rc(str);//rc 
	}
	return 0;
	
}