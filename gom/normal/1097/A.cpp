#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
string s,t;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>s;
    for(int i=0;i<5;i++){
        cin>>t;
        if(t[0]==s[0]||t[1]==s[1]){
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";
    return 0;
}