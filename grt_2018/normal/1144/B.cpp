#include <bits/stdc++.h>

using namespace std;

int n;
vector<int>odd;
vector<int>even;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0; i<n;i++){
        int a;
        cin>>a;
        if(a&1) odd.push_back(a);
        else even.push_back(a);
    }
    sort(odd.begin(),odd.end());
    sort(even.begin(),even.end());
    int m = min(odd.size(),even.size())+1;
    //cout<<m<<"\n";
    int s = 0;
    for(int i=0; i<(int)odd.size()-m; i++) {
        s+=odd[i];
    }
    for(int i=0; i<(int)even.size()-m;i++)
        s+=even[i];
    cout<<s;
    return 0;
}