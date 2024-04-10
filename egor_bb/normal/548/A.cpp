#include <iostream>
#include <string>
using namespace std;

string s;
int k;
int main(){
getline (cin, s);
cin >> k;
int n = s.size();
if (n % k ==0){
n = n / k;
for (int i = 0; i < s.size(); i += n){
for (int j = i; j < i + n / 2; j++){
if (s[j] != s[i + n - (j - i) - 1]) {
cout << "NO\n";
return 0;
}
}
}
} else {
cout << "NO\n";
return 0;
}
cout << "YES\n";

}