#include<bits/stdc++.h>
using namespace std;
int main(){
    int len,num1=0,num2=0;
    string s;
    cin>>len;
    cin>>s;
    for(int i=0;i<len;i++){
        if(s[i]=='1'){
            num1++;
        }
        else num2++;
    }
    
    cout<<len-2*min(num1,num2);
    return 0;
}