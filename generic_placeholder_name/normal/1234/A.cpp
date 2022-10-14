#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
    int q; cin>>q; for(int l=1; l<=q; l++) {
        int n; cin>>n; int tmp, sum=0; for(int i=0; i<n; i++) {
            cin>>tmp; sum+=tmp;
        }
        cout<<(int)ceil((double)sum/n)<<endl;
    }
}