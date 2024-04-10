#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
    int n, k; cin>>n>>k; int a[n]; for(int i=0; i<n; i++) cin>>a[i]; vector<int> curr;
    for(int i=0; i<n; i++) {
        bool chk=0;
        for(int j=0; j<curr.size(); j++) {
            if(curr[j]==a[i]) chk=1;
        }
        if (!chk) {
            if (curr.size()<k) curr.push_back(a[i]);
            else {
                curr.erase(curr.begin()); curr.push_back(a[i]);
            }
        }
    }
    cout<<curr.size()<<endl;
    for(int i=curr.size()-1; i>=0; i--) cout<<curr[i]<<" ";
}