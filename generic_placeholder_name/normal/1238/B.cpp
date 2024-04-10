#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int q; cin>>q; for(int l=1; l<=q; l++) {
        int n, r, tmp; cin>>n>>r; vector<int> a; for(int i=0; i<n; i++) {cin>>tmp; a.push_back(tmp);} sort(a.begin(), a.end());
        for(int i=1; i<a.size(); i++) {
            if(a[i]==a[i-1]) {a.erase(a.begin()+i-1); i--;}
        }
        if (a.size()==1) cout<<1<<endl;
        else {
            bool c=0;
            for(int i=0; i<a.size(); i++) {
                if(!c&&a[a.size()-i-1]-r*i<=0) {cout<<i<<endl; c=1;}
            }
            if(!c)cout<<a.size()<<endl;
        }
    }
}