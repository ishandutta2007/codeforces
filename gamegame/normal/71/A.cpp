#include<iostream>
using namespace std;
int n;
string s;
int main(){
        ios::sync_with_stdio(false);
        cin >> n;getline(cin,s);
        for(int i=1; i<=n ;i++){
                getline(cin,s);
                if(s.size()<=10) cout << s << endl;
                else cout << s[0] << s.size()-2 << s.back() << endl;
                }
        }