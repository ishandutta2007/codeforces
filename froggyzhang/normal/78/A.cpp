#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
	    x=(x<<3)+(x<<1)+c-'0';c=getchar();
	}
	return x*f;
}
string a,b,c;
bool check(char c){
	return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
}
int main(){
	getline(cin,a);
	getline(cin,b);
	getline(cin,c);
	int tot=0;
	for(int i=0;i<a.length();i++){
		if(check(a[i])){
			tot++;
		}
	}
	if(tot!=5){
		cout<<"NO"<<endl;
		return 0;
	}
	tot=0;
	for(int i=0;i<b.length();i++){
		if(check(b[i])){
			tot++;
		}
	}
	if(tot!=7){
		cout<<"NO"<<endl;
		return 0;
	}
	tot=0;
	for(int i=0;i<c.length();i++){
		if(check(c[i])){
			tot++;
		}
	}
	if(tot!=5){
		cout<<"NO"<<endl;
		return 0;
	}
	cout<<"YES"<<endl;
	return 0;
}