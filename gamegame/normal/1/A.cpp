#include<iostream>
using namespace std;
int main(){
long long int x,y,z;
cin >> x >> y >> z;
x=x+z-1;
y=y+z-1;
x=x/z;
y=y/z;
cout << x*y << endl;
}