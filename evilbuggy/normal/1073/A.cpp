#include <bits/stdc++.h>

using namespace std;

int a[26], len;

bool isDiverse(){
    for(int i = 0; i < 26; i++){
        if(2*a[i] > len)return false;
    }
    return true;
}

int main(){
    
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;

    string s;
    cin>>s;
    for(int i = 0; i < n; i++){
        memset(a, 0, sizeof(a));
        len = 0;
        for(int j = i; j < n; j++){
            a[s[j]-'a']++;
            len++;
            if(isDiverse()){
                cout<<"YES\n"<<s.substr(i, j-i+1)<<endl;
                exit(0);
            }
        }
    }
    cout<<"NO"<<endl;
}