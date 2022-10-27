#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    string str;
    cin>>t;
    while(t--){
        cin>>str;
        int c = 0, s = 0, d = 0;
        for(int i = 0; i < str.size(); i++){
            if(str[i] >= 'A' && str[i] <= 'Z')c++;
            if(str[i] >= 'a' && str[i] <= 'z')s++;
            if(str[i] >= '0' && str[i] <= '9')d++;
        }
        if(c > 0 && s > 0 && d > 0){
            cout<<str<<endl;
        }else if(c > 0 && s > 0){
            for(int i = 0; i < str.size(); i++){
                if(c > 1 && str[i] >= 'A' && str[i] <= 'Z'){
                    str[i] = '0';
                    cout<<str<<endl;
                    break;
                }
                if(s > 1 && str[i] >= 'a' && str[i] <= 'z'){
                    str[i] = '0';
                    cout<<str<<endl;
                    break;
                }
            }
        }else if(c > 0 && d > 0){
            for(int i = 0; i < str.size(); i++){
                if(c > 1 && str[i] >= 'A' && str[i] <= 'Z'){
                    str[i] = 'a';
                    cout<<str<<endl;
                    break;
                }
                if(d > 1 && str[i] >= '0' && str[i] <= '9'){
                    str[i] = 'a';
                    cout<<str<<endl;
                    break;
                }
            }
        }else if(s > 0 && d > 0){
            for(int i = 0; i < str.size(); i++){
                if(s > 1 && str[i] >= 'a' && str[i] <= 'z'){
                    str[i] = 'A';
                    cout<<str<<endl;
                    break;
                }
                if(d > 1 && str[i] >= '0' && str[i] <= '9'){
                    str[i] = 'A';
                    cout<<str<<endl;
                    break;
                }
            }
        }else if(c > 0){
            str[0] = '0';
            str[1] = 'a';
            cout<<str<<endl;
        }else if(s > 0){
            str[0] = '0';
            str[1] = 'A';
            cout<<str<<endl;
        }else if(d > 0){
            str[0] = 'a';
            str[1] = 'A';
            cout<<str<<endl;
        }
    }
}