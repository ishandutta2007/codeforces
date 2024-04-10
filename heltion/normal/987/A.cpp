#include<bits/stdc++.h>
using namespace std;
string s1[6] = {"Power", "Time", "Space", "Soul",  "Reality", "Mind"};
string s2[6] = {"purple", "green", "blue", "orange",  "red", "yellow"};
set<string> s;
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i += 1){
        string x;
        cin >> x;
        s.insert(x);
    }
    cout << 6 - n << endl;
    for(int i = 0; i < 6; i += 1)
        if(s.count(s2[i]) == 0) cout << s1[i] << endl;
}