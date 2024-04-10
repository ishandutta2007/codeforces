#include <iostream>
using namespace std;
#include<bits/stdc++.h>
int main() {
    string s;
    cin>>s;
    int l=s.size();
    int a=0,b=0;
    for(int i=0;i<l;i++){
        if(s[i] >='a' && s[i]<='z' )a++;
        else b++;
    }
    if(a>=b){
        for(int i=0;i<l;i++){
            if(s[i] >='a' && s[i]<='z' )printf("%c",s[i]);
            else printf("%c",s[i]+'a'-'A');
        }
    }
    else for(int i=0;i<l;i++){
            if(s[i] >='a' && s[i]<='z' )printf("%c",s[i]+'A'-'a');
            else printf("%c",s[i]);
        }
    
	return 0;
}