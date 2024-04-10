#include<iostream>
#include<cstdio>
using namespace std;
int T,k;int GCD(int a,int b){return b?GCD(b,a%b):a;}
int main(){cin>>T;while(T--)cin>>k,cout<<100/GCD(k,100)<<endl;return 0;}