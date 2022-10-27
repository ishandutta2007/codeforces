#include <bits/stdc++.h>

using namespace std;

map<char, int> vow;

void init(){
    vow['a'] = vow['e'] = vow['i'] = vow['o'] =  vow['u'] = vow['y'] = 1;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    string s,t = "";
    cin>>s;
    init();
    bool tmp = false;
    for(size_t i = 0; i < n; i++){
        if(vow[s[i]] == 1){
            if(tmp){
                continue;
            }else{
                tmp = true;
                t = t + s[i];
            }
        }else{
            tmp = false;
            t = t + s[i];
        }
    }
    cout<<t<<endl;
}