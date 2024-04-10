#include<algorithm>
#include<iostream>
#include<string>
using namespace std;
int T,N;string a;int main(){cin>>T;while(T--)cin>>N>>a,sort(a.begin(),a.end()),cout<<a<<endl;return 0;}