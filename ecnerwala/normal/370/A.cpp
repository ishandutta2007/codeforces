#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int r1, c1, r2, c2;

int numKing() {
return max(abs(r1 - r2), abs(c1 - c2));
}

int numBish() {
if((r1 + r2 + c1 + c2)%2 != 0) return 0;
if(r1 + c1 == r2 + c2) return 1;
if(r1 - c1 == r2 - c2) return 1;
return 2;
}

int numRook() {
if(r1 == r2 || c1 == c2) return 1;
return 2;
}

int main(){
cin >> r1 >> c1 >> r2 >> c2;
cout << numRook() << ' ' << numBish() << ' ' << numKing() << '\n';
return 0;
}