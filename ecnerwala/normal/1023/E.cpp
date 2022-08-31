#include<bits/stdc++.h>
using namespace std;
bool q(int a, int b, int c, int d) {
 cout<<"? "<<a<<' '<<b<<' '<<c<<' '<<d<<endl;
 string s;cin>>s;
 return s[0]=='Y';
}
int main() {
 ios_base::sync_with_stdio(0);
 int N;cin>>N;
 string a,b;
 int x=1,y=1;
 while(x+y<=N) {
  if(q(x+1,y,N,N)) {a+='D',x++;}
  else {a+='R',y++;}
 }
 x=N,y=N;
 while(x+y>N+1){
  if(q(1,1,x,y-1)) {b+='R',y--;}
  else {b+='D',x--;}
 }
 reverse(b.begin(),b.end());
 cout<<"! "<<a<<b<<endl;
}