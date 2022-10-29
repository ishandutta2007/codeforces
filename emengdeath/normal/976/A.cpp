#include<bits/stdc++.h>
using namespace std;
int n;
int num;
bool sig;
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    while (n--){
        char c;
        cin>>c;
        num+=(c=='0');
        if (c=='1')sig=1;
    }
    if (sig)cout<<1;
    while (num--)cout<<0;
    return 0;
}