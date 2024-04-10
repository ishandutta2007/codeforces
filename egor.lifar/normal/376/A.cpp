#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
#include <map>
#include <set>


using namespace std;


int main() {
    string s;
    cin >> s;
    long long k =  s.size();
    long long l = 0;
    for (int i = 0; i < k; i++){
        if(s[i] == '^'){
            l = i;
        }
    }
    vector< pair<int, int> > v;
    for (int i = 0; i < k; i++){
        if(s[i] != '^' && s[i] != '='){
            v.push_back(make_pair(s[i] - '0', l - i));
        }
    }
    long long ss = 0, s2 = 0;
    for (int i = 0; i < (int)v.size(); i++) {
        if(v[i].second < 0){
            ss += v[i].first * v[i].second  * -1;
        }else {
            s2 += v[i].first * v[i].second ;
        }
    }
    if(ss == s2){
        cout << "balance" << endl;
    }else{
        if(ss > s2){
            cout << "right" << endl;
        }else{
            cout << "left" << endl;
        }
    }
    return 0;
}