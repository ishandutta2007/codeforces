#include<iostream>
using namespace std;
int main(){
    bool iIn1,iIn2,iIn3,iIn4;
    cin>>iIn1>>iIn2>>iIn3>>iIn4;
    bool ans=((iIn1^iIn2)&(iIn3|iIn4))^((iIn2&iIn3)|(iIn1^iIn4));
    cout<<ans;
}