#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin>>s;
    int bro = -1, brc = -1, col1 = -1, col2 = -1;
    int cnt = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '['){
            bro = i;
            break;
        }
    }
    if(bro == -1){
        cout<<-1<<endl;
        return 0;
    }
    for(int i = bro + 1; i < s.size(); i++){
        if(s[i] == ':'){
            col1 = i;
            break;
        }
    }
    if(col1 == -1){
        cout<<-1<<endl;
        return 0;
    }
    for(int i = s.size() - 1; i > col1; i--){
        if(s[i] == ']'){
            brc = i;
            break;
        }
    }
    if(brc == -1){
        cout<<-1<<endl;
        return 0;
    }
    for(int i = brc - 1; i > col1; i--){
        if(s[i] == ':'){
            col2 = i;
            break;
        }
    }
    if(col2 == -1){
        cout<<-1<<endl;
        return 0;
    }
    for(int i = col1 + 1; i < col2; i++){
        if(s[i] == '|')cnt++;
    }
    cout<<cnt+4<<endl;
}