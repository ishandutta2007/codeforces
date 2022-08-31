#include<bits/stdc++.h>
using namespace std;
bool lower(char c){
    return (65<=c && c<=90);
}
int main(){
    string s,low="",up="";
    int L=0,U=0;
    cin >> s;
    for(int i=0;i<s.length();i++){
        if(lower(s[i])){
            string t=" ",u=" ";
            t[0]=s[i];
            u[0]=s[i]+32;
            low+=t;
            up+=u;
            L++;
        }
        else{
            string t=" ",u=" ";
            t[0]=s[i]-32;
            u[0]=s[i];
            low+=t;
            up+=u;
            U++;
        }
    }
    if(L<=U){
        cout << up;
    }
    else{
        cout << low;
    }
    //oops I messed up the ASCII codes
}