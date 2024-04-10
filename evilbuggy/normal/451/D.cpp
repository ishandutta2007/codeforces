#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;

int cnta[2], cntb[2];

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
    cnta[0] = cnta[1] = cntb[0] = cntb[1] = 0;
    ll sume = 0, sumo = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'a'){
            cnta[i&1]++;
            sumo += cnta[i&1];
            sume += cnta[(i&1)^1];
        }else{
            cntb[i&1]++;
            sumo += cntb[i&1];
            sume += cntb[(i&1)^1];
        }
    }
    cout<<sume<<" "<<sumo<<endl;
}