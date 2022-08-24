#include<iostream>
using namespace std;
int main(){
    string s;
    getline(cin,s);
    long long ans=0;
    for(int i=0; i<s.size() ;i++){
        if(s[i]>=65 && s[i]<=90){
            ans+=s[i]-64;
        }
        else if(s[i]>=97 && s[i]<=122){
            ans-=s[i]-96;
        }
    }
    cout << ans << endl;
}