#include<bits/stdc++.h>
using namespace std;
int main(int a){
    cin>>a;
    int s=0;
    while(a)s+=a%8==1,a/=8;
    cout<<s<<endl;
}