#include<cstdio>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
string t[5]={"Sheldon","Leonard","Penny","Rajesh","Howard"};
main(){
  int n;
  cin>>n;
  --n;
  while(n>=5){
    n-=5;
    n/=2;
  }
  cout<<t[n]<<endl;
}