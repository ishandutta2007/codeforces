#include<bits/stdc++.h>
using namespace std;
int main(){
	int x;
	cin>>x;
	map<string ,int> m;
	int o=0;
	for(int i=0;i<x;i++){
		string str;
		cin>>str;
		int pointer=0;
		while(pointer<str.size()){
			if(str[pointer]=='u'){
				str[pointer]='o';
				str.insert(pointer,"o");
				pointer=0;
			}else if(pointer!=0&&str[pointer]=='h'&&str[pointer-1]=='k'){
				str.erase(str.begin()+pointer-1);
				pointer=0;
			}else{
				pointer++;
			}
		}
		if(m[str]==0){
			o++;
			m[str]++;
		}
	}
	cout<<o<<endl;
}