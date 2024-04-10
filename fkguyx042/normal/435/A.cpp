#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
int n,m;
cin >> n >> m;
int cnt = 0, sum = 0;
for(int i = 0 ; i < n; ++ i){
int a;
cin >> a;
if(sum + a > m){
cnt++;
sum = a;
}else if(sum+a == m){
cnt++;
sum = 0;
}else{
sum +=a;
}
}
if(sum > 0) cnt++;
cout<<cnt<<endl;
}