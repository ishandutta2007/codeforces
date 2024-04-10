#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);

    string s;
    cin>>s;
    vector<pair<int,int>> a={{1,1}, {1,2}, {1,3}, {1,4}};
    vector<pair<int,int>> b={{3,1}, {3,3}, {4,1}, {4,3}};
    for(int i=0,j=0,h=0; i<s.size(); i++){
        if(s[i]=='0'){
            cout<<a[j].fi<<" "<<a[j].se<<"\n";
            j=(j+1)%4;
        }else{
            cout<<b[h].fi<<" "<<b[h].se<<"\n";
            h=(h+1)%4;
        }
    }
}